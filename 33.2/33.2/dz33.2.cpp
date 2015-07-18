#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;

class Stack
{
public:
	Stack()
	{
		top = -1;
		stack = new int[max];
		if (!stack)
			throw 0;
	}
	void Add(int newnum)
	{
		if (top == max - 1)
			throw 1;
		else
			stack[++top] = newnum;
	}
	void Pop()
	{
		if (top == 0)
			throw 2;
		else
			cout << stack[top--] << endl;
	}
private:
	int top;
	int max = 10;
	int* stack;
};

int main()
{
	srand(time(NULL));
	try{
		Stack test;
		for (int i = 0; i < 15; i++){
			test.Add(rand() % 20);
		}
	}
	catch (int a){
		if (a == 0)
			cout << "Memory error\n";
		else if (a == 1)
			cout << "Stack is full\n";
		else
			cout << "Stack is ampty\n";
	}
	try{
		Stack test;
		for (int i = 0; i < 10; i++){
			test.Add(rand() % 20);
		}
		for (int i = 0; i < 15; i++){
			test.Pop();
		}
	}
	catch (int a){
		if (a == 0)
			cout << "Memory error\n";
		else if (a == 1)
			cout << "Stack is full\n";
		else
			cout << "Stack is ampty\n";
	}
}
