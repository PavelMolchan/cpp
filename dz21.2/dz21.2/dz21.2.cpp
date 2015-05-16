#include <iostream>
#include <string>

using namespace std;

struct String
{
public:
	String()
	{
		s = new char[80];

	}
	String(int a)
	{
		s = new char[a];

	}
	String(char* a)
	{
		s = new char[strlen(a) + 1];
		strcpy(s, a);
	}
	~String()
	{
		if (s){
			delete[] s;
		}
	}
	void Scan()
	{
		cout << "Enter your text" << endl;
		cin >> s;
	}
	void Print() const
	{
		cout << s << endl;
	}
private:
	char* s;
};





void main()
{
	String A;
	String B(5);
	B.Scan();
	String C("unit");
	A.Print();
	B.Print();
	C.Print();

}