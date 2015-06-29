#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String();
	~String();
	void InitStr(char* dat);
	char* GetStr()
	{
		return str;
	}
	int GetLen()
	{
		return len;
	}
	String operator* (String& str2);
	void InsertChar(char ch, int pos);
	void PrintANCII();
	String& operator=(const String& str2);
	void UpReg();
	void DownReg();
	bool operator<(const String& strn);
	bool operator>(const String& strn);
	operator int()
	{
		return len;
	}
	void Print()
	{
		cout << str << endl;
	}
private:
	char* str;
	int len;
};

String::String()
{
	len = 0;
	str = nullptr;
};
String::~String()
{
	delete[] str;
};

void String::InitStr(char* dat)
{
	if (len){
		len = 0;
		delete[] str;
	}
	len = strlen(dat);
	str = new char[len + 1];
	strcpy(str, dat);
};

String String::operator* (String& str2)
{
	String newstr;
	newstr.len = len + str2.len;
	newstr.str = new char[newstr.len + 1];
	strcpy(newstr.str, str);
	strcat(newstr.str, str2.str);
	return newstr;
};

void String::InsertChar(char ch, int pos)
{
	if (pos<len){
		char* newstr = new char[len + 2];
		for (int i = 0; i < len + 2; i++){
			if (i < pos){
				newstr[i] = str[i];
			}
			else if (i == pos){
				newstr[i] = ch;
			}
			else{
				newstr[i] = str[i - 1];
			}
		}
	}
	else
		cout << "Wrong position/n";
};

void String::PrintANCII()
{
	for (int i = 0; i<len; i++){
		cout << (int)str[i] << " ";
	}
	cout << endl;
};

String& String::operator=(const String& strn)
{
	if (this == &strn)
		return*this;
	if (len != strn.len){
		delete[] str;
		len = strn.len;
		str = new char[len + 1];
	}
	strcpy(str, strn.str);
	return *this;
};

void String::UpReg()
{
	for (int i = 0; i < len; i++){
		if (str[i] >= 'a'&&str[i] <= 'z'){
			str[i] -= 32;
		}
	}
};

void String::DownReg()
{
	for (int i = 0; i < len; i++){
		if (str[i] >= 'A'&&str[i] <= 'Z'){
			str[i] += 32;
		}
	}
};
bool String::operator<(const String& strn)
{
	if (!strcmp(str, strn.str))
		return true;
	else
		return false;
};

class Queue
{
public:
	Queue();
	~Queue();
	void Add(const String& str);
	void Extract();
	String& Access(int pos);
	bool Empty()
	{
		if (len)
			return true;
		else
			return false;
	}
	int GetLen()
	{
		return len;
	}
	Queue& operator=(const Queue& q);
	void Print();
private:
	String* que;
		int len;
};

Queue::Queue()
{
	que= nullptr;
	len = 0;
};
Queue::~Queue()
{
	delete[] que;
};

void Queue::Add(const String& str)
{
	if (len){
		String* newque =new String[++len];
		for (int i = 0; i<len - 1; i++){
			newque[i] = que[i];
		}
		delete[] que;
		que = new String[len];
		for (int i = 0; i<len - 1; i++){
			que[i] = newque[i];
		}
		que[len - 1] = str;
	}
	else{
		que = new String[++len];
		que[0] = str;
	}
};

void Queue::Extract()
{
	String* newque = new String[--len];
	for (int i = 0; i<len; i++){
		newque[i] = que[i + 1];
	}
	delete[] que;
	que = new String[len];
	for (int i = 0; i<len; i++){
		que[i] = newque[i];
	}
	delete[]newque;
};

String& Queue::Access(int pos)
{
	if (pos <= len)
		return que[pos];
	else
		return que[len-1];
};

Queue& Queue::operator=(const Queue& q)
{
	if (this == &q)
		return*this;
	if (len != q.len){
		delete[] que;
		len = q.len;
		que = new String[len];
	}
	for (int i = 0; i < len; i++){
		que[i] = q.que[i];
	}
	return *this;
};

void Queue::Print()
{
	for (int i = 0; i < len; i++){
		que[i].Print();
	}
	cout << endl;
};

int main()
{
	String A,B,C,D;
	A.InitStr("First");
	B.InitStr("Second");
	C.InitStr("Third");
	D.InitStr("Fourth");
	Queue Test1;
	Test1.Add(A);
	Test1.Add(B);
	Test1.Add(C);
	Test1.Add(D);
	Test1.Print();
	Test1.Extract();
	Test1.Print();
	Test1.Access(1) = A;
	Test1.Print();
	if (Test1.Empty())
		cout << "Queue is full\n";
	else
		cout << "Queue is empty\n";
	Queue Test2;
	if (Test2.Empty())
		cout << "Queue is full\n";
	else
		cout << "Queue is empty\n";
	cout << Test1.GetLen() << endl;
	cout << Test2.GetLen() << endl;
	Test2.Add(A);
	Test2.Add(B);
	Test2.Add(C);
	Test2.Add(D);
	Test1 = Test2;
	Test1.Print();
}