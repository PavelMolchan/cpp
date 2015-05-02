#include <iostream>
#include <string>

using namespace std;

class student
{
	string name;
	string surname;
	int year;
public:
	void rec(string a, string b, int c)
	{
		name = a;
		surname = b;
		year = c;
	}
	void show()
	{
		cout << name << " " << surname << " " << year << endl;
	}
};

class group
{
	int numbergroup;
	int namberstud;
	student* info;
public:
	group()
	{
		cout << "Enter group number" << endl;
		cin >> numbergroup;
		cout << "Enter number of students" << endl;
		cin >> namberstud;
		info = new student[namberstud];
	}
	~group()
	{
		delete[]info;
	}
	void recgroup()
	{
		string s1, s2;
		int n1;
		for (int i = 0; i < namberstud; i++){
			cout << "Enter students name" << endl;
			cin >> s1;
			cout << "Enter students surname" << endl;
			cin >> s2;
			cout << "Enter students date of birth" << endl;
			cin >> n1;
			info[i].rec(s1, s2, n1);
			system("cls");
		}
	}
	void showgroup()
	{
		cout << "Number of group is " << numbergroup << endl;
		cout << "The group consists of " << namberstud << " students:" << endl;
		for (int i = 0; i < namberstud; i++){
			cout << i+1 << ". ";
			info[i].show();
		}
	}

};

void main()
{
	group test;
	test.recgroup();
	test.showgroup();

}