#include <iostream>
#include<string>

using namespace std;

class Time
{
public:
	Time()
	{
		SetTime();
	}
	void SetTime()
	{
		int hours1, minutes1;
		string note1;
		cout << "Enter hours(<=12)\n";
		cin >> hours1;
		getchar();
		if (hours1 > 12 || hours1 < 0){
			cout << "Wrong number\n";
			hours = 10;
		}
		else
			hours = hours1;
		cout << "Enter minutes(<=59)\n";
		cin >> minutes1;
		getchar();
		if (hours1>59 || hours1 < 0){
			cout << "Wrong number\n";
			hours = 10;
		}
		else
			minutes = minutes1;
		cout << "Enter am or pm\n";
		//cin.getline(note1,3);
		cin >> note1;
		if (note1 != "am" && note1 != "pm"){
			cout << "Wrong note\n";
			note = "am";
		}
		else
			note = note1;
	}
	Time operator=(Time& sctm)
	{
		if (this == &sctm){
			return *this;
		}
		else
		{
			hours = sctm.hours;
			minutes = sctm.minutes;
			note = sctm.note;
			return *this;
		}
	}
	Time operator+(int min)
	{
		minutes = minutes + min;
		note = note;
		while (minutes > 59)
		{
			minutes -= 60;
			hours++;
		}
		while (hours > 12){
			hours -= 12;
			if (note == "pm")
				note = "am";
			else
				note = "pm";
		}
		return *this;
	}
	Time operator-(int min)
	{
		minutes = minutes - min;
		note = note;
		while (minutes < 0)
		{
			minutes += 60;
			hours--;
		}
		while (hours <= 0){
			hours += 12;
			if (note == "pm")
				note = "am";
			else
				note = "pm";
		}
		return *this;
	}
	void Show()
	{
		cout << hours << "\:" << minutes << " " << note << endl;
	}
	bool operator<(Time& sctm)
	{
		if (note == "am"&&sctm.note == "pm")
			return false;
		else if (note == "pm"&&sctm.note == "am")
			return true;
		else if (note == sctm.note){
			if (hours < sctm.hours)
				return true;
			else if (hours > sctm.hours)
				return false;
			else if (hours == sctm.hours){
				if (minutes<sctm.minutes)
					return true;
				else if (minutes >= sctm.minutes)
					return false;
			}
		}
	}
	bool operator>(Time& sctm)
	{
		return (sctm < *this);
	}
	void Convert()
	{
		cout << "Time is ";
		if (note == "pm"){
			if (hours == 12)
				cout << "00:";
			else
				cout << hours + 12 << ":";
		}
		else{
			cout << hours << ":";
		}
		cout << minutes << endl;
	}
private:
	int hours;
	int minutes;
	string note;
};

int main()
{
	Time A;
	A.Show();
	A = A + 121;
	A.Show();
	A = A - 121;
	A.Show();
	A.Convert();
	Time B;
	B.Convert();
	if (A > B)
		cout << "A>B\n";
	else
		cout << "A<B\n";
	if (A < B)
		cout << "A<B\n";
	else
		cout << "A>B\n";
	return 0;
}