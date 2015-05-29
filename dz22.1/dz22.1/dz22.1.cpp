#include <iostream>

using namespace std;

class Date
{
public:
	Date(int a, int b, int c)
	{
		year = a;
		month = b;
		day = c;
	}
	int operator-(Date a2)
	{
		Date a1(*this);
		int res = 0;
		if ((year < a2.year) || ((year == a2.year) && (month < a2.month)) || ((year == a2.year) && (month == a2.month) && (day < a2.day))){
			swap(a1, a2);
		}
		for (int i = a2.year; i <= a1.year; i++){
			int min = 1, max = 12;
			if (i == a2.year){
				min = a2.month+1;
			}
			if (i == a1.year){
				max = a1.month - 1;
			}
			for (int j = min; j <= max; ++j){
				switch (j){
				case 1:res += 31; break;
				case 2:res += 28;
					if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)){
						res++;
					}
					break;
				case 3:res += 31; break;
				case 4:res += 30; break;
				case 5:res += 31; break;
				case 6:res += 30; break;
				case 7:res += 31; break;
				case 8:res += 31; break;
				case 9:res += 30; break;
				case 10:res += 31; break;
				case 11:res += 30; break;
				case 12:res += 31; break;
				}
			}
		}
		res += a1.day;
		switch (a2.month){
		case 1:res += 31 - a2.day; break;
		case 2:res += 28 - a2.day;
			if (((a1.year % 4 == 0) && (a1.year % 100 != 0)) || (a1.year % 400 == 0)){
				res++;
			}
			break;
		case 3:res += (31 - a2.day); break;
		case 4:res += (30 - a2.day); break;
		case 5:res += (31 - a2.day); break;
		case 6:res += (30 - a2.day); break;
		case 7:res += (31 - a2.day); break;
		case 8:res += (31 - a2.day); break;
		case 9:res += (30 - a2.day); break;
		case 10:res += (31 - a2.day); break;
		case 11:res += (30 - a2.day); break;
		case 12:res += (31 - a2.day); break;
		}
		return res;
	}
private:
	int year, month, day;
};




void main()
{
	Date A(2015, 3, 12);
	Date B(2014, 5, 9);
	int a = A - B;
	cout << a << endl;
}