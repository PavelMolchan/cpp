#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Element
{
	int data;
	Element* Next;
};

class List
{
public:
	List(){
		Head = Tail = nullptr;
		Count = 0;
	}
	~List()
	{
		DelList();
	}
	void Add(int dt)
	{
		Element* current = Head;
		Element* prev;
		Element* added = new Element;
		added->data = dt;
		added->Next = nullptr;
		if (Head){
			while (current->Next && dt >= current->data){
				prev = current;
				current = current->Next;
			}
			if (current->data <= dt){
				prev = current->Next;
				current->Next = added;
				added->Next = prev;
			}
			else{
				added->Next = current;
				if (Head == current)
					Head = added;
				else
					prev->Next = added;

			}

			if (!added->Next)
				Tail = added;
		}
		else{
			Head = Tail = added;
		}
		Count++;
	}
	void Del()
	{
		Element* deleted = Head;
		Head = Head->Next;
		delete deleted;
		Count--;
	}
	void DelList()
	{
		while (Head != 0)
			Del();
	}
	void Print()
	{
		Element* printed = Head;
		while (printed != 0)
		{
			cout << printed->data << " ";
			printed = printed->Next;
		}
		cout << endl;
	}
	int GetCount()
	{
		return Count;
	}
	void Revers()
	{
		if (Head == Tail)
			return;
		else{
			Element* Head2;
			Element* current;
			Element* prev;
			int num = Count - 1;
			while (num > 0){
				current = Head;
				for (int i = num; i > 0; i--){
					prev = current;
					current = current->Next;
				}
				current->Next = prev;
				if (num==1){
					Tail = prev;
					prev->Next = nullptr;
				}
				if (current == Tail)
					Head2 = current;
				num--;
			}
			Head = Head2;

		}
	}
private:
	Element* Head;
	Element* Tail;
	int Count;
};

void main()
{
	srand(time(NULL));
	List Test;
	for (int i = 0; i < 10; i++){
		Test.Add(rand() % 99);
	}
	Test.Print();
	Test.Del();
	Test.Del();
	Test.Print();
	Test.Revers();
	Test.Print();
}