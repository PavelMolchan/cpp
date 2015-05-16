#include <iostream>
#include <string>

using namespace std;

struct Person
{
public:
	Person(string a, int b, char c, string d);
	void Print();
	void Name(string a);
	void Age(int a);
	void Gender(char a);
	void Phone(string a);

private:
	string name;
	int age;
	char gender;
	string phone;
};

Person::Person(string a, int b, char c, string d)
{
	name = a;
	age = b;
	gender = c;
	phone = d;
}

void Person::Print()
{
	cout << name << " " << age << " " << gender << " " << phone << endl;
}

void Person::Name(string a)
{
	cout << this->name << " replaced with " << a << endl;
	name = a;
}

void Person::Age(int a)
{
	cout << this->age << " replaced with " << a << endl;
	age = a;
}

void Person::Gender(char a)
{
	cout << this->gender << " replaced with " << a << endl;
	gender = a;
}

void Person::Phone(string a)
{
	cout << this->phone << " replaced with " << a << endl;
	phone = a;
}

int main()
{
	Person A("Petrov", 56, 'm', "333555");
	A.Print();
	A.Name("Sidorova");
	A.Age(18);
	A.Gender('w');
	A.Phone("111222");
	A.Print();
}