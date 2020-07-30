#include "MarkDown.h"

using namespace std;



	markdown::markdown(const string& filename)
		:_root(new Node(nul))
		, _filename(filename)
	{
	}

	void markdown::transform()
	{
		//��Ŀ���ļ�
		ifstream fin(_filename);
		if (!fin.is_open())
		{
			cout << "file: " << _filename << "open failed" << endl;
			return;
		}

		//����Ƿ�Ϊ����
		bool isBlock = false;

		//���ж�ȡ�ļ�����
		string lineStr;
		while (!fin.eof())
		{
			getline(fin, lineStr);


			//Ԥ����ȥ��������Ч�ַ����ո�
			const char* start = processStr(lineStr.c_str());

			//�﷨����,�����﷨�ڵ�
			//1.�п�
			if (!isBlock && start == nullptr)
				continue;

			//2.�ж��Ƿ�Ϊ�ָ���
			if (!isBlock && isLine(start))
			{
				_root->_child.push_back(new Node(hr));
				continue;
			}

			//�ж���������
			pair<int, const char*> lineType = parseType(start);

			//a,����Ǵ����
			if (lineType.first == blockcode)
			{
				//������ǵ�һ�γ���,���������
				if (!isBlock)
				{
					_root->_child.push_back(new Node(blockcode));
				}
				//�Դ����ǽ���ȡ����������ż���μ�⵽������ʱ������ǽ��иı�
				isBlock = !isBlock;
				continue;
			}
			//�����������ֱ�Ӵ洢δ����ǰ���ַ���
			if (isBlock)
			{
				_root->_child.back()->elem[0] += lineStr;
				_root->_child.back()->elem[0] += "\n";
				continue;
			}

			//b,�������ͨ����
			if (lineType.first == paragraph)
			{
				_root->_child.push_back(new Node(paragraph));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

			//c,����Ǳ���
			if (lineType.first >= h1 && lineType.first <= h6)
			{
				_root->_child.push_back(new Node(lineType.first));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

			//d,�����б�
			if (lineType.first == ul)
			{
				//�ж��ǲ��ǵ�һ�����ֵ������б�
				if (_root->_child.empty() || _root->_child.back()->_type != ul)
				{
					_root->_child.push_back(new Node(ul));
				}
				_root->_child.back()->_child.push_back(new Node(li));
				insert(_root->_child.back()->_child.back(), lineType.second);
				continue;
			}

			//d,�����б�
			if (lineType.first == ol)
			{
				//�ж��ǲ��ǵ�һ�����ֵ������б�
				if (_root->_child.empty() || _root->_child.back()->_type != ol)
				{
					_root->_child.push_back(new Node(ol));
				}
				_root->_child.back()->_child.push_back(new Node(li));
				insert(_root->_child.back()->_child.back(), lineType.second);
				continue;
			}

			//e,���ý��

			if (lineType.first == quote)
			{
				_root->_child.push_back(new Node(quote));
				insert(_root->_child.back(), lineType.second);
				continue;
			}

		}

		//�����﷨��������HTML�ĵ�
		dfs(_root);
	}

	//ʹ��������ȱ��������﷨��ת��Ϊhtml�ĵ�
	void markdown::dfs(Node* root)
	{

		//����ǰ�ñ�ǩ
		_content += frontTag[root->_type];

		//���뵱ǰ����
		//�������ݴ���
		//1.��ַ
		if (root->_type == href)
		{
			_content += "<a href=\"";
			_content += root->elem[1];
			_content += "\">";
			_content += root->elem[0];
			_content += "</a>";
		}
		//2.ͼƬ
		else if (root->_type == image)
		{
			_content += "<img alt=\"";
			_content += root->elem[0];
			_content += "\" src=\"";
			_content += root->elem[1];
			_content += "\" />";
		}
		//��ͨ����
		else
		{
			_content += root->elem[0];
		}

		//�����ӽڵ�
		for (auto a : root->_child)
			dfs(a);

		//������ñ�ǩ
		_content += backTag[root->_type];
	}


	//���ַ���������
	void markdown::insert(Node* child, const char* str)
	{
		//����Ƿ����ڴ���
		bool incode = false;
		//����Ƿ�Ϊ������
		bool instrong = false;
		//����Ƿ�Ϊб��
		bool inem = false;
		//����Ƿ�Ϊɾ����
		bool indline = false;
		//����һ�����ı����
		child->_child.push_back(new Node(nul));
		int size = strlen(str);
		//һ�δ���һ���ַ�
		for (int i = 0; i < size; i++)
		{
			//���ڴ���
			if (str[i] == '`')
			{
				if (incode)
				{
					//�����ǰ�����ڴ������λ�ã�����һ���½ڵ㣬����������
					child->_child.push_back(new Node(nul));
				}
				else
				{
					child->_child.push_back(new Node(code));
				}
				incode = !incode;
				continue;
			}

			//����
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

			//б��
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

			//ͼƬ
			if (str[i] == '!' && i + 1 < size && str[i + 1] == '[')
			{
				//����ͼƬ�ڵ�
				child->_child.push_back(new Node(image));
				i += 2;
				//���ͼƬ����
				for (; i < size && str[i] != ']'; i++)
				{
					child->_child.back()->elem[0] += str[i];
				}
				//���ͼƬ��ַ
				i += 2;
				for (; i < size && str[i] != ')'; i++)
				{
					child->_child.back()->elem[1] += str[i];
				}
				//����һ���ڵ㣬���ͼƬ������
				child->_child.push_back(new Node(nul));
				continue;
			}

			//����
			if (str[i] == '[' && !incode)
			{
				//�������ӽڵ�
				child->_child.push_back(new Node(href));
				++i;
				//���������
				for (; i + 1 < size && str[i] != ']'; i++)
				{
					child->_child.back()->elem[0] += str[i];
				}
				i += 2;
				//������ӵ�ַ
				for (; i + 1 < size && str[i] != ')'; i++)
				{
					child->_child.back()->elem[1] += str[i];
				}
				//����һ���ڵ㣬������Ӻ�����
				child->_child.push_back(new Node(nul));
				continue;
			}

			//ɾ����
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

			//ע�Ͳ���Ҫ�����⴦��

			//��ͨ�ı�
			child->_child.back()->elem[0] += str[i];


		}
	}

	//�ж�����,��piar�����﷨���ͣ��Լ��������ݵ���ʼλ��
	pair<int, const char*> markdown::parseType(const char* str)
	{
		//����Ǵ�����еĿ���
		if (str == nullptr)
			return make_pair(nul, nullptr);

		const char* ptr = str;

		//1���ж��Ƿ�Ϊ����
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
		//������ָ�븴λ�������ж�
		ptr = str;

		//2���ж��Ƿ�Ϊ �����
		if (strncmp(ptr, "```", 3) == 0)
		{
			return make_pair(blockcode, ptr + 3);
		}

		//3���ж��Ƿ�Ϊ �����б�
		if (strncmp(ptr, "- ", 2) == 0)
		{
			return make_pair(ul, ptr + 2);
		}

		//4���ж��Ƿ�Ϊ �����б�
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
		//������ָ�븴λ�������ж�
		ptr = str;

		//5.�ж��Ƿ�Ϊ ����
		if (strncmp(ptr, "> ", 2) == 0)
		{
			return make_pair(quote, ptr + 2);
		}

		//6.������������ ����ͨ����
		return make_pair(paragraph, str);
	}

	//�ж��Ƿ��Ƿָ���
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

	//ȥ��������Ч�ַ�
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

	//��ȡ����
	string markdown::getContent()
	{
		return _content;
	}

	//����HTML�ĵ�
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

	//����
	void markdown::destory(Node* root)
	{
		if (root)
		{
			for (auto ch : root->_child)
				destory(ch);

			delete root;
		}
	}

	//����
	markdown::~markdown()
	{
		if (_root)
			destory(_root);
	}
