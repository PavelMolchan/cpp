#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Element
{
	int data;
	Element *Next, *Prev;
};

class List
{
public:
	List()
	{
		Head = Tail = NULL;
		Count = 0;
	}
	~List()
	{
		DellList();
	}
	void Add(int dat)
	{
		Element* added = new Element;
		added->Next = 0;
		added->data = dat;
		added->Prev = Tail;
		if (Tail != 0)
			Tail->Next = added;
		if (Count == 0)
			Head = Tail = added;
		else
		Tail = added;
		Count++;
		}
	int GetCount()
	{
		return Count;
	}
	void DellList()
	{
		while (Head != 0)
			Del();
	}
	void Del()
	{
		Element* deleted = Head;
		Head = Head->Next;
		delete deleted;
		Count--;
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
private:
	Element * Head, *Tail;
	int Count;
};

void main()
{
	srand(time(NULL));
	List Test;
	for (int i = 0; i < 10; i++){
		Test.Add(rand() % 100);
	}
	Test.Print();
	Test.Del();
	Test.Del();
	Test.Print();
}

