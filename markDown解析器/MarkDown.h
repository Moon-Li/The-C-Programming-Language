#ifndef __MarkDown_h__
#define __MarkDown_h__
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

// 词法关键字枚举
enum Token {
	nul = 0,
	paragraph = 1,
	href = 2,
	ul = 3,
	ol = 4,
	li = 5,
	em = 6,
	strong = 7,
	hr = 8,
	image = 9,
	quote = 10,
	h1 = 11,
	h2 = 12,
	h3 = 13,
	h4 = 14,
	h5 = 15,
	h6 = 16,
	blockcode = 17,
	code = 18,
	dline = 19,
};

// HTML前置标签
const std::string frontTag[] = {
	"", "<p>", "", "<ul>", "<ol>", "<li>", "<em>", "<strong>", "<hr color=#CCCCCC size=1/ >",
	"", "<blockquote>", "<h1>", "<h2>", "<h3>", "<h4>", "<h5>", "<h6>",
	"<pre><code>", "<code>", "<strike>"};
// HTML 后置标签
const std::string backTag[] = {
	"", "</p>", "", "</ul>", "</ol>", "</li>", "</em>",
	"</strong>", "", "", "</blockquote>", "</h1>", "</h2>",
	"</h3>", "</h4>", "</h5>", "</h6>", "</code></pre>", "</code>", "</strike>" };

struct Node
{
	//分析出的语法类型
	int _type;

	//用孩子节点储存包含的子语法
	vector<Node*> _child;

	//内容
	//elem[0]保存要显示的内容
	//elem[1]保存路径以及网址
	string elem[2];

	Node(int type)
	:_type(type)
	{
	}

};

class markdown
{
public:
	markdown(const string& filename);

	//打开，读取文件
	void transform();

	//使用深度优先遍历，把语法树转换为html文档
	void dfs(Node* root);

	//逐字符插入内容
	void insert(Node* child, const char* str);

	//判断类型,用piar返回语法类型，以及真正内容的起始位置
	pair<int, const char*> parseType(const char* str);

	//判断是否是分割线
	bool isLine(const char* str);

	//去除行首无效字符
	const char* processStr(const char* str);
	
	//获取内容
	string getContent();

	//生成HTML文件
	void createHtml();

	//销毁
	void destory(Node* root);

	~markdown();

private:
	//根节点
	Node* _root;

	//文件名
	string _filename;
	//文档内容
	string _content;

};


#endif
