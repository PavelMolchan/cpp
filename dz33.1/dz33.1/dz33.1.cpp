#include <iostream>
#include <cmath>

using namespace std;

void GetNum()
{
	cout << "Put number\n";
	char num[128];
	cin.getline(num, sizeof(num));
	int len;
	len = strlen(num);
	int finnum = 0;
	int max = INT_MAX;
	int count = 0;
	do{
		if (max > 10){
			max = (max - max % 10) / 10;
			++count;
		}
		else{
			max = 0;
			++count;
		}
	} while (max);
	max = INT_MAX;
	int* maxarr = new int[count];
	for (int i = count - 1; i >= 0; --i){
		maxarr[i] = max % 10;
		if (max > 10){
			max = (max - max % 10) / 10;
		}
	}
	int pref = 1;
	try{
		for (int i = 0; i < len; i++){
			if (num[i]<'0'||num[i]>'9'){
				throw 0;
			}
		}
		int* num2;
		if (num[0] == '-'){
			pref = -1;
			len -= 1;
			num2 = new int[len];
			for (int i = 0; i < len; ++i){
				switch(num[i+1])
				{
				case '0':num2[i] = 0; break;
				case '1':num2[i] = 1; break;
				case '2':num2[i] = 2; break;
				case '3':num2[i] = 3; break;
				case '4':num2[i] = 4; break;
				case '5':num2[i] = 5; break;
				case '6':num2[i] = 6; break;
				case '7':num2[i] = 7; break;
				case '8':num2[i] = 8; break;
				case '9':num2[i] = 9; break;
				}
			}
		}
		else
		{
			num2 = new int[len];
			for (int i = 0; i < len; ++i){
				switch (num[i])
				{
				case '0':num2[i] = 0; break;
				case '1':num2[i] = 1; break;
				case '2':num2[i] = 2; break;
				case '3':num2[i] = 3; break;
				case '4':num2[i] = 4; break;
				case '5':num2[i] = 5; break;
				case '6':num2[i] = 6; break;
				case '7':num2[i] = 7; break;
				case '8':num2[i] = 8; break;
				case '9':num2[i] = 9; break;
				}
			}
		}
		if (len > count)
			throw 1;
		if (len == count){
			for (int i = 0; i<count; ++i){
				if (num2[i]>maxarr[i])
					throw 1;
			}
		}
		for (int i = 0; i < len; ++i){
			finnum = finnum + num2[i] * pow(10,len - 1 - i);
		}
		cout << finnum*pref << endl;;
	}
	catch (int a){
		if (a == 0)
			cout << "Wrong character\n";
		else
			cout << "Size of number is owerlimit\n";

	}

}



int main()
{
	GetNum();
}