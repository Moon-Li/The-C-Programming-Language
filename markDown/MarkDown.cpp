#include "MarkDown.h"

using namespace std;



	markdown::markdown(const string& filename)
		:_root(new Node(nul))
		, _filename(filename)
	{
	}

	void markdown::transform()
	{
		//打开目标文件
		ifstream fin(_filename);
		if (!fin.is_open())
		{
			cout << "file: " << _filename << "open failed" << endl;
			return;
		}

		//标记是否为代码
		bool isBlock = false;

		//按行读取文件内容
		string lineStr;
		while (!fin.eof())
		{
			getline(fin, lineStr);


			//预处理，去除行首无效字符（空格）
			const char* start = processStr(lineStr.c_str());

			//语法分析,创建语法节点
			//1.判空
			if (!isBlock && start == nullptr)
				continue;

			//2.判断是否为分割线
			if (!isBlock && isLine(start))
			{
				_root->_child.push_back(new Node(hr));
				continue;
			}

			//判断其他类型
			pair<int, const char*> lineType = parseType(start);

			//a,如果是代码块
			if (lineType.first == blockcode)
			{
				//代码块标记第一次出现,创建代码块
				if (!isBlock)
				{
					_root->_child.push_back(new Node(blockcode));
				}
				//对代码标记进行取反，方便在偶数次检测到代码标记时，将标记进行改变
				isBlock = !isBlock;
				continue;
			}
			//代码块中内容直接存储未处理前的字符串
			if (isBlock)
			{
				_root->_child.back()->elem[0] += lineStr;
				_root->_child.back()->elem[0] += "\n";
				continue;
			}

			//b,如果是普通段落
			if (lineType.first == paragraph)
			{
				_root->_child.push_back(new Node(paragraph));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

			//c,如果是标题
			if (lineType.first >= h1 && lineType.first <= h6)
			{
				_root->_child.push_back(new Node(lineType.first));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

			//d,无序列表
			if (lineType.first == ul)
			{
				//判断是不是第一个出现的无序列表
				if (_root->_child.empty() || _root->_child.back()->_type != ul)
				{
					_root->_child.push_back(new Node(ul));
				}
				_root->_child.back()->_child.push_back(new Node(li));
				insert(_root->_child.back()->_child.back(), lineType.second);
				continue;
			}

			//d,有序列表
			if (lineType.first == ol)
			{
				//判断是不是第一个出现的无序列表
				if (_root->_child.empty() || _root->_child.back()->_type != ol)
				{
					_root->_child.push_back(new Node(ol));
				}
				_root->_child.back()->_child.push_back(new Node(li));
				insert(_root->_child.back()->_child.back(), lineType.second);
				continue;
			}

			//e,引用结点

			if (lineType.first == quote)
			{
				_root->_child.push_back(new Node(quote));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

		}

		//遍历语法树，生成HTML文档
		dfs(_root);
	}

	//使用深度优先遍历，把语法树转换为html文档
	void markdown::dfs(Node* root)
	{

		//插入前置标签
		_content += frontTag[root->_type];

		//插入当前内容
		//特殊内容处理
		//1.网址
		if (root->_type == href)
		{
			_content += "<a href=\"";
			_content += root->elem[1];
			_content += "\">";
			_content += root->elem[0];
			_content += "</a>";
		}
		//2.图片
		else if (root->_type == image)
		{
			_content += "<img alt=\"";
			_content += root->elem[0];
			_content += "\" src=\"";
			_content += root->elem[1];
			_content += "\" />";
		}
		//普通内容
		else
		{
			_content += root->elem[0];
		}

		//处理子节点
		for (auto a : root->_child)
			dfs(a);

		//插入后置标签
		_content += backTag[root->_type];
	}


	//逐字符插入内容
	void markdown::insert(Node* child, const char* str)
	{
		//标记是否行内代码
		bool incode = false;
		//标记是否为粗体内
		bool instrong = false;
		//标记是否为斜体
		bool inem = false;
		//标记是否为删除线
		bool indline = false;
		//创建一个纯文本结点
		child->_child.push_back(new Node(nul));
		int size = strlen(str);
		//一次处理一个字符
		for (int i = 0; i < size; i++)
		{
			//行内代码
			if (str[i] == '`')
			{
				if (incode)
				{
					//如果当前是行内代码结束位置，创建一个新节点，存后面的内容
					child->_child.push_back(new Node(nul));
				}
				else
				{
					child->_child.push_back(new Node(code));
				}
				incode = !incode;
				continue;
			}

			//粗体
			if (str[i] == '*' && i + 1 < size && str[i + 1] == '*' && !incode)
			{
				if (instrong)
				{
					child->_child.push_back(new Node(nul));
				}
				else
				{
					child->_child.push_back(new Node(strong));
				}
				instrong = !instrong;
				++i;
				continue;
			}

			//斜体
			if (str[i] == '_' && !incode)
			{
				if (inem)
				{
					child->_child.push_back(new Node(nul));
				}
				else
				{
					child->_child.push_back(new Node(em));
				}
				inem = !inem;
				continue;
			}

			//图片
			if (str[i] == '!' && i + 1 < size && str[i + 1] == '[')
			{
				//创建图片节点
				child->_child.push_back(new Node(image));
				i += 2;
				//存放图片名字
				for (; i < size && str[i] != ']'; i++)
				{
					child->_child.back()->elem[0] += str[i];
				}
				//存放图片地址
				i += 2;
				for (; i < size && str[i] != ')'; i++)
				{
					child->_child.back()->elem[1] += str[i];
				}
				//创建一个节点，存放图片后内容
				child->_child.push_back(new Node(nul));
				continue;
			}

			//链接
			if (str[i] == '[' && !incode)
			{
				//创建连接节点
				child->_child.push_back(new Node(href));
				++i;
				//存放链接名
				for (; i + 1 < size && str[i] != ']'; i++)
				{
					child->_child.back()->elem[0] += str[i];
				}
				i += 2;
				//存放连接地址
				for (; i + 1 < size && str[i] != ')'; i++)
				{
					child->_child.back()->elem[1] += str[i];
				}
				//创建一个节点，存放连接后内容
				child->_child.push_back(new Node(nul));
				continue;
			}

			//删除线
			if (str[i] == '~' && i+1 < size && str[i + 1] == '~')
			{
				if (!indline)
				{
					child->_child.push_back(new Node(dline));
				}
				else
				{
					child->_child.push_back(new Node(nul));
				}
				indline = !indline;
				i++;
				continue;
			}

			//注释不需要做特殊处理

			//普通文本
			child->_child.back()->elem[0] += str[i];


		}
	}

	//判断类型,用piar返回语法类型，以及真正内容的起始位置
	pair<int, const char*> markdown::parseType(const char* str)
	{
		//如果是代码块中的空行
		if (str == nullptr)
			return make_pair(nul, nullptr);

		const char* ptr = str;

		//1、判断是否为标题
		int num = 0;
		while (*ptr && *ptr == '#')
		{
			++ptr;
			++num;
		}
		if (*ptr == ' ' && num > 0 && num <= 6)
		{
			return make_pair(h1 + num - 1, ptr + 1);
		}
		//若不是指针复位，重新判断
		ptr = str;

		//2、判断是否为 代码块
		if (strncmp(ptr, "```", 3) == 0)
		{
			return make_pair(blockcode, ptr + 3);
		}

		//3、判断是否为 无序列表
		if (strncmp(ptr, "- ", 2) == 0)
		{
			return make_pair(ul, ptr + 2);
		}

		//4、判断是否为 有序列表
		if (*ptr > '0' && *ptr < '9')
		{
			while (*ptr > '0' && *ptr < '9')
			{
				++ptr;
			}
			if (*ptr && *ptr == '.')
			{
				++ptr;
				if (*ptr && *ptr == ' ')
					return make_pair(ol, ptr + 1);
			}
		}
		//若不是指针复位，重新判断
		ptr = str;

		//5.判断是否为 引用
		if (strncmp(ptr, "> ", 2) == 0)
		{
			return make_pair(quote, ptr + 2);
		}

		//6.不是以上类型 即普通段落
		return make_pair(paragraph, str);
	}

	//判断是否是分割线
	bool markdown::isLine(const char* str)
	{
		int num = 0;
		while (*str && *str == '-')
		{
			++str;
			++num;
		}
		return num >= 3;
	}

	//去除行首无效字符
	const char* markdown::processStr(const char* str)
	{
		while (*str)
		{
			if (*str == ' ' || *str == '/t')
				++str;
			else
				break;
		}
		if (*str == '\0')
			return nullptr;
		return str;
	}

	//获取内容
	string markdown::getContent()
	{
		return _content;
	}

	//生成HTML文档
	void markdown::createHtml()
	{
		std::string head =
			"<!DOCTYPE html><html><head>\
			<meta charset=\"utf-8\">\
			<title>Markdown</title>\
			<link rel=\"stylesheet\" href=\"github-markdown.css\">\
			</head><body><article class=\"markdown-body\">";
		std::string end = "</article></body></html>";
		
		ofstream fout("my.html");
		fout << head << _content << end;
	}

	//销毁
	void markdown::destory(Node* root)
	{
		if (root)
		{
			for (auto ch : root->_child)
				destory(ch);

			delete root;
		}
	}

	//析构
	markdown::~markdown()
	{
		if (_root)
			destory(_root);
	}
