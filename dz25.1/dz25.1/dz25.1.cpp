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
	Complex(int _real, int _imag) :real(_real), imag(_imag){}
	Complex(const Complex& num2)
	{
		real = num2.real;
		imag = num2.imag;
	}
	void Print()
	{
		cout << real;
		if (imag > 0)
			cout << "+i" << imag << endl;
		else if (imag < 0)
			cout << "-i" << -1 * imag << endl;
		else
			cout << endl;
	}
	Complex operator= (const Complex& num2)
	{
		if (this == &num2){
			return *this;
		}
		else
		{
			real = num2.real;
			imag = num2.imag;
			return *this;
		}
	}
	Complex operator+(const Complex& num2)
	{
		Complex Res;
		Res.real = real + num2.real;
		Res.imag = imag + num2.imag;
		return Res;
	}
	Complex operator-(const Complex& num2)
	{
		Complex Res;
		Res.real = real - num2.real;
		Res.imag = imag - num2.imag;
		return Res;
	}
	Complex operator*(const Complex& num2)
	{
		Complex Res;
		Res.real = real*num2.real - imag*num2.imag;
		Res.imag = imag*num2.real + real*num2.imag;
		return Res;
	}
	Complex operator/(const Complex& num2)
	{
		Complex Res;
		Res.real = (real*num2.real + imag*num2.imag) / (num2.real*num2.real + num2.imag*num2.imag);
		Res.imag = (real*num2.real - imag*num2.imag) / (num2.real*num2.real + num2.imag*num2.imag);
		return Res;
	}
private:
	float real;
	float imag;
};

int main()
{
	Complex A(3, 6);
	A.Print();
	Complex B(5, 4);
	B.Print();
	Complex C;
	C = A + B;
	C.Print();
	C = C - B;
	C.Print();
	C = A*B;
	C.Print();
	C = A / B;
	C.Print();
}