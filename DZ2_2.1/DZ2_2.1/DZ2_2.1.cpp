#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class MyStack
{
public:
	MyStack();
	~MyStack();
	void Insert(int num);
	void Extract();
	void Print();

private:
	int top;
	int count;
	int* stack;
};

MyStack::MyStack()
{
	top = -1;
	count = 0;
}

MyStack::~MyStack()
{
	delete[] stack;
}

void MyStack::Insert(int num)
{
	if (count){
		if (top == count-1){
			int* newstack = new int[++count];
			top++;
			for (int i = 0; i < top; i++){
				newstack[i] = stack[i];
			}
			newstack[top] = num;
			delete[] stack;
			stack = new int[count];
			for (int i = 0; i < count; i++){
				stack[i] = newstack[i];
			}
			delete[] newstack;
		}
		else{
			stack[++top] = num;
		}
	}
	else{
		stack = new int[++count];
		top++;
		stack[0] = num;
	}
	cout << "Insert " << num << endl;
};

void MyStack::Extract()
{
	cout<<"Extracting " << stack[top--] << endl;
};

void MyStack::Print()
{
	cout << "Stack contain:\n";
	for(int i = 0; i <= top; i++){
		cout << stack[i]<<endl;
	}
};


int main()
{
	srand(time(NULL));
	MyStack Test;
	for (int i = 0; i < 10; i++){
		Test.Insert(rand() % 99);
	}
	Test.Print();
	for (int i = 1; i <= 5; i++){
		Test.Extract();
	}
	Test.Print();
	for (int i = 0; i < 10; i++){
		Test.Insert(rand() % 99);
	}
	Test.Print();
}
