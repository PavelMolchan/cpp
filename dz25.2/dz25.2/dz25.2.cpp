#include<iostream>
#include<time.h>
#include<string>

using namespace std;

class BlackJack
{
public:
	BlackJack()
	{
		sizehand = sizediller = summdiller = summhand = 0;
		flag = false;
		GetComand("card");
	}
	void GetComand(string str)
	{
		if (str == "card") {
			if (sizehand == 0){
				sizehand = sizediller = 2;
				hand = new int[sizehand];
				diller = new int[sizediller];
				for (int i = 0; i < sizehand; ++i) {
					hand[i] = rand() % 10 + 2;
					diller[i] = rand() % 10 + 2;
					summdiller += diller[i];
					summhand += hand[i];
				}
			}
			else {
				int* newhand = new int[sizehand + 1];
				for (int i = 0; i < sizehand; ++i) {
					newhand[i] = hand[i];
				}
				newhand[sizehand++] = rand() % 10 + 2;
				summhand += newhand[sizehand - 1];
				delete[]hand;
				hand = new int[sizehand];
				for (int i = 0; i < sizehand; ++i) {
					hand[i] = newhand[i];
				}
				if (summdiller < 17){
					int* newdiller = new int[sizediller + 1];
					for (int i = 0; i < sizediller; ++i) {
						newdiller[i] = diller[i];
					}
					newdiller[sizediller++] = rand() % 10 + 2;
					summdiller += newdiller[sizediller - 1];
					delete[]diller;
					diller = new int[sizediller]; 
					for (int i = 0; i < sizediller; ++i) {
						diller[i] = newdiller[i];
					}
				}
			}
		}
		else if (str == "firstdeal") {

			if (summhand == 21 && summdiller == 21) {
				ShowAll();
				cout << "Black Jack!!!You win 1 rate\n";
				win++;
				flag = true;
			}
			else if (summhand == 21 && summdiller != 21) {
				ShowAll();
				cout << "Black Jack!!!You win 3 rates\n";
				win += 3;
				flag = true;
			}
			else if (summhand != 21 && summdiller == 21) {
				ShowAll();
				cout << "Diller have Black Jack!!!You loose 1 rates\n";
				win --;
				flag = true;
			}
			else if (summhand > 21&&summdiller<21) {
				ShowAll();
				cout << "You lose 1 rate\n";
				win--;
				flag = true;
			}
			else if (summdiller > 21&&summhand<21) {
				ShowAll();
				cout << "You win 1 rate\n";
				win++;
				flag = true;
			}
		}
		else if (str == "deal"){
			GetComand("firstdeal");
			if (summdiller > 21 && summhand > 21 || summdiller == summhand) {
				ShowAll();
				cout << "you have you rate\n";
				flag = true;
			}
			else if (summdiller > summhand) {
				ShowAll();
				cout << "You lose 1 rate\n";
				win--;
				flag = true;
			}
			else if (summdiller < summhand) {
				ShowAll();
				cout << "You win 1 rate\n";
				win++;
				flag = true;
			}
		}
		else if (str == "end"){
			cout << "You bank have " << win << " rates.";
			if (win>0){
				cout << " YOU WIN!!!\n\n";
			}
			else if (win < 0){
				cout << " YOU LOOSE!!!\n\n";
			}
		}
		else if (str == "more"){
			delete[] hand;
			delete[] diller;
			sizehand = sizediller = summdiller = summhand = 0;
			flag = false;
			GetComand("card");
		}
	}

	void Show()
	{
		cout << "Diller have: ";
		for (int i = 0; i < sizediller; ++i) {
			if (i == 0){
				cout << diller[i];
			}
			else {
				cout << "?";
			}
			if (i == sizediller - 1) {
				cout << " = ";
			}
			else {
				cout << " + ";
			}
		}
		cout << "?\n";
		cout << "You have: ";
		for (int i = 0; i < sizehand; ++i) {
			cout << hand[i];
			if (i == sizehand - 1) {
				cout << " = ";
			}
			else {
				cout << " + ";
			}
		}
		cout << summhand << endl;
	}
	bool GetFlag()
	{
		return flag;
	}
private:
	void ShowAll()
	{
		cout << "Diller have: ";
		for (int i = 0; i < sizediller; ++i) {
			cout << diller[i];
			if (i == sizediller - 1) {
				cout << " = ";
			}
			else {
				cout << " + ";
			}
		}
		cout << summdiller<<endl;
		cout << "You have: ";
		for (int i = 0; i < sizehand; ++i) {
			cout << hand[i];
			if (i == sizehand - 1) {
				cout << " = ";
			}
			else {
				cout << " + ";
			}
		}
		cout << summhand << endl;
	}
	int* hand;
	int sizehand;
	int* diller;
	int sizediller;
	int win=1;
	int summdiller;
	int summhand;
	bool flag;

};

int main()
{
	srand(time(NULL));
	string command;
	BlackJack Test;
	do{
		if (!Test.GetFlag()){
			system("cls");
			Test.Show();
			Test.GetComand("firstdeal");
		}
		if (Test.GetFlag()) {
			cout << "Enter your command(more,end)\n";
		}
		else {
			cout << "Enter your command(deal,card,end)\n";
		}
		cin >> command;
		Test.GetComand(command);
	} while (command != "end");
}