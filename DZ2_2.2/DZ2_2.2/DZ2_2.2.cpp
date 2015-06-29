#include <iostream>
#include <cstring>

using namespace std;

class Check
{
public:
	Check(char* str);
	~Check();
	void Print();
	void Result();

private:
	void Insert(char ch);
	void Extract(char ch);
	void ToStack(char* str);
	int top;
	int count;
	char* stack;
};

Check::Check(char* str)
{
	top = -1;
	count = 0;
	ToStack(str);
}

Check::~Check()
{
	if (count)
	delete[] stack;
}

void Check::Insert(char ch)
{
	if (count){
		if (top == count - 1){
			char* newstack = new char[++count];
			top++;
			for (int i = 0; i < top; i++){
				newstack[i] = stack[i];
			}
			newstack[top] = ch;
			delete[] stack;
			stack = new char[count];
			for (int i = 0; i < count; i++){
				stack[i] = newstack[i];
			}
			delete[] newstack;
		}
		else{
			stack[++top] = ch;
		}
	}
	else{
		stack = new char[++count];
		top++;
		stack[0] = ch;
	}
	cout << "Insert " << ch << endl;
};

void Check::Extract(char ch)
{
	if (stack[top]==ch)
	cout << "Extracting " << stack[top--] << endl;
};

void Check::Print()
{
	cout << "Stack contain:\n";
	for (int i = 0; i <= top; i++){
		cout << stack[i] << endl;
	}
};

void Check::ToStack(char* str)
{
	int len = strlen(str);
	for (int i = 0; i <= len; i++){
		if (str[i] == '{')
			Insert('}');
		else if (str[i] == '[')
			Insert(']');
		else if (str[i] == '(')
			Insert(')');
		else if (str[i] == '}')
			Extract('}');
		else if (str[i] == ']')
			Extract(']');
		else if (str[i] == ')')
			Extract(')');
	}
};

void Check::Result()
{
	if (top>-1)
		cout << "Wrong\n";
	else
		cout << "Right\n";
};

int main()
{
	char exampl[]="{[()]}";
	Check Test(exampl);
	Test.Result();
	char exampl2[] = "{[()}";
	Check Test2(exampl2);
	Test2.Result();
}
