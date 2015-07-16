#include <iostream>
#include <math.h>

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
		for (int i = len; i < -1; i--){
			if ('0' > num[i] && '9' < num[i]){
				throw 0;
			}
		}
		int* num2;
		if (num[0] == '-'){
			pref = -1;
			len -= 1;
			num2 = new int[len];
			for (int i = 0; i < len; ++i){
				num2[i] = (int)num[i + 1];
			}
		}
		else
		{
			num2 = new int[len];
			for (int i = 0; i < len; ++i){
				num2[i] = num[i];
				cout << num2[i] << endl;
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
			finnum = finnum + num2[i] * 10 ^ (len - 1 - i);
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