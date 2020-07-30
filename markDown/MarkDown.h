#ifndef __MarkDown_h__
#define __MarkDown_h__
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

// �ʷ��ؼ���ö��
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

// HTMLǰ�ñ�ǩ
const std::string frontTag[] = {
	"", "<p>", "", "<ul>", "<ol>", "<li>", "<em>", "<strong>", "<hr color=#CCCCCC size=1/ >",
	"", "<blockquote>", "<h1>", "<h2>", "<h3>", "<h4>", "<h5>", "<h6>",
	"<pre><code>", "<code>", "<strike>"};
// HTML ���ñ�ǩ
const std::string backTag[] = {
	"", "</p>", "", "</ul>", "</ol>", "</li>", "</em>",
	"</strong>", "", "", "</blockquote>", "</h1>", "</h2>",
	"</h3>", "</h4>", "</h5>", "</h6>", "</code></pre>", "</code>", "</strike>" };

struct Node
{
	//���������﷨����
	int _type;

	//�ú��ӽڵ㴢����������﷨
	vector<Node*> _child;

	//����
	//elem[0]����Ҫ��ʾ������
	//elem[1]����·���Լ���ַ
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

	//�򿪣���ȡ�ļ�
	void transform();

	//ʹ��������ȱ��������﷨��ת��Ϊhtml�ĵ�
	void dfs(Node* root);

	//���ַ���������
	void insert(Node* child, const char* str);

	//�ж�����,��piar�����﷨���ͣ��Լ��������ݵ���ʼλ��
	pair<int, const char*> parseType(const char* str);

	//�ж��Ƿ��Ƿָ���
	bool isLine(const char* str);

	//ȥ��������Ч�ַ�
	const char* processStr(const char* str);
	
	//��ȡ����
	string getContent();

	//����HTML�ļ�
	void createHtml();

	//����
	void destory(Node* root);

	~markdown();

private:
	//���ڵ�
	Node* _root;

	//�ļ���
	string _filename;
	//�ĵ�����
	string _content;

};


#endif
