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
	char* operator*(const String& s1)
	{
		char* temp=new char[256];
		int k = 0;
		for (int i = 0; i < strlen(s); i++){
			for (int j = 0; j < strlen(s1.s); j++){
				if (s[i] == s1.s[j]){
					temp[k] = s[i];
					k++;
				}
			}
		}
		char* temp2 = new char[k+1];
		strncpy(temp2, temp,k);
		return temp;
	}
	

private:
	char* s;
};



void main()
{

	String C("unit");
	String D("ui");
	String E =C*D;
	E.Print();
}