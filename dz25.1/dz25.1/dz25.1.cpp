#include <iostream>

using namespace std;

class Complex
{
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(int _real,int _imag):real(_real),imag(_imag){}

	void Print()
	{
		cout << real;
		if (imag>0)
			cout << "+i" << imag<<endl;
		else if (imag < 0)
			cout << "-i" << -1 * imag << endl;
		else
			cout << endl;
	}

private:
	int real;
	int imag;
};

int main()
{
	Complex A;
	Complex B(1, 1);
	Complex C(-1, 1);
	Complex D(1, -1);
	Complex E(-1,-1);
	A.Print();
	B.Print();
	C.Print();
	D.Print();
	E.Print();
}