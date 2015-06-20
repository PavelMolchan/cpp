#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Abonent
{
	Abonent(int number, char* name)
	{
		Phonenumber = number;
		strcpy(Soname, name);
	}
	int Phonenumber;
	char Soname[32];
	Abonent* left = NULL;
	Abonent* right = NULL;
	Abonent* parent = NULL;
};

class Base
{
public:
	Base()
	{
		root = NULL;
	}
	~Base()
	{
		Del();
	}
	void Del()
	{
		Abonent* current = root;
		Abonent* t;
		while (root != 0){
			while (current->left != 0 && current->right != 0){
				if (current->right != 0){
					current = current->right;
				}
				else if (current->left != 0){
					current = current->left;
				}
			}
			t = current;
			current = current->parent;
			if (current->right == t){
				current->right = NULL;
			}
			else{
				current->left = NULL;
			}
			current = current->parent;
		}
	}
	Abonent* FindAbonent(char* name = NULL)
	{
		Abonent* current = root;
		if (name){
			while (current != 0 && strcmp(name, current->Soname) != 0)
			{
				if (strcmp(name, current->Soname) < 0){
					current = current->left;
				}
				else{
					current = current->right;
				}
				if (current){
					FILE* src = fopen("search.txt", "a");
					fputs("was searched", src);
					fputs(current->Soname, src);
					fwrite(&current->Phonenumber, sizeof(int), 1, src);
					fclose(src);
					return current;
				}
				else{
					return NULL;
					cout << "no matches\n";
				}
			}
		}

		else {
			cout << "Enter soname\n";
			cin >> name;
			return FindAbonent(name);
		}
	}
	void AddAbonent(Abonent* past)
	{
		if (past != 0){
			Abonent* current = root;
			Abonent* prev = NULL;
			while (current != 0){
				prev = current;
				if (strcmp(past->Soname, current->Soname) < 0)
					current = current->left;
				else
					current = current->right;


			}
			past->parent = prev;
			if (prev == 0){
				root = past;
			}
			else if (strcmp(past->Soname, prev->Soname) < 0){
				prev->left = past;
			}
			else{
				prev->right = past;
			}
		}
	}
	void DellAbonent(Abonent* req)
	{
		if (req != 0){
			Abonent* current = FindAbonent(req->Soname);
			if ((current->left != 0) && (current->right != 0)){
				if (current->parent->right == current){
					current->parent->right = current->right;
					AddAbonent(current->left);
					delete current;
				}
				else if (current->parent->left == current){
					current->parent->left = current->left;
					AddAbonent(current->right);
					delete current;
				}
			}
			else if (current->left == 0){
				current->parent->right = current->right;
				AddAbonent(current->left);
				delete current;
			}
			else if (current->right == 0){
				current->parent->left = current->left;
				AddAbonent(current->right);
				delete current;
			}
			else{
				if (current->parent->right == current){
					current->parent->right = 0;
					delete current;
				}
				else if (current->parent->left == current)
					current->parent->left = 0;
				delete current;
			}
		}
	}
	void ChangeAbonent(Abonent* change)
	{
		cout << "Enterr \"1\", if you neded change soname,\"2\", if you neded change phonenumber, or \"3\", if you neded change bouth of them\n ";
		int flag;
		cin >> flag;
		char* newname;
		int newnumber;
		if (flag == 1){
			cout << "Please enter new soname\n";
			cin >> newname;
			Abonent* newab;
			strcpy(newab->Soname, newname);
			newab->Phonenumber = change->Phonenumber;
			DellAbonent(change);
			AddAbonent(newab);
		}
		else if (flag == 2){
			cout << "Please enter new phonenumber\n";
			cin >> newnumber;
			change->Phonenumber = newnumber;
		}
		else if (flag == 3){
			cout << "Please enter new soname\n";
			cin >> newname;
			Abonent* newab;
			strcpy(newab->Soname, newname);
			newab->Phonenumber = change->Phonenumber;
			DellAbonent(change);
			AddAbonent(newab);
			cin >> newnumber;
			change->Phonenumber = newnumber;
		}
		else{
			cout << "Wrong number\n";
		}
	}
	void DiapPrint(char* first, char* lust)
	{
		Abonent* current = FindAbonent(first);
		Abonent* upper;
		FILE* src = fopen("search.txt", "a");
		if (current){
			while (strcmp(current->Soname, lust) < 0 || current->left != 0){
				fputs("was requaered abonent list:", src);
				fputs(current->Soname, src);
				fwrite(&current->Phonenumber, sizeof(int), 1, src);
				cout << current->Soname << " " << current->Phonenumber << endl;
				if (current->right != 0){
					while (current->left != 0){
						current = current->left;
					}
				}
				upper = current->parent;
				while (upper != 0 && current != upper->right){
					current = upper;
					upper = upper->parent;
				}
			}
		}
		else{
			while (current->left != 0){
				current = current->left;
			}
			while (strcmp(current->Soname, first) < 0 && current->right != 0){
				if (current->right != 0){
					while (current->left != 0){
						current = current->left;
					}
				}
				upper = current->parent;
				while (upper != 0 && current != upper->right){
					current = upper;
					upper = upper->parent;
				}
			}
			if (current->right == 0){
				cout << "Noi results/n";
			}
			else{
				DiapPrint(current->Soname, lust);
			}
		}
		fclose(src);
	}
private:
	Abonent* root;

};

int main()
{
	Base Test;
	Abonent A(2501010, "Ivanov");
	Abonent B(2502020, "Petrov");
	Abonent C(2503030, "Sidorov");
	Abonent D(2504040, "Pupkin");
	Abonent E(2505050, "Andreev");
	Test.AddAbonent(&A);
	Test.AddAbonent(&B);
	Test.AddAbonent(&C);
	Test.AddAbonent(&D);
	Test.AddAbonent(&E);
}