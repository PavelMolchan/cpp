#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

class array
{public:
	array()
	{
		arr = NULL;
		size = 0;
	}
	array(int i)
	{
		srand(time(NULL));
		size = i;
		arr = new int[i];
		for (int i = 0; i < size; i++){
			arr[i] = rand() % 99;
		}
	}
	~array()
	{
		if (size){
			delete[]arr;
			arr = NULL;
			size = 0;
		}
	}
	int& operator[](int i)
	{
		if (i < size){
			return arr[i];
		}
		else{
			cout << "wrong parameter\n";
		}
	}
	array& operator=(const array& a)
	{
		if (this == &a){
			return *this;

		}
		if (size != a.size) {
			delete[]arr;
			size = a.size;
			arr = new int[size];
		}
		for (int i = 0; i < size; i++){
			arr[i] = a.arr[i];
		}
		return *this;
	}
	array& operator+(array& a)
	{
		if (size == 0){
			return a;
		}
		else if ((a.size == 0) || (a.size == 0 && size == 0)){
			return *this;
		}
		else{
			int* temp = new int[size];
			for (int i = 0; i < size; i++){
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = new int[size + a.size];
			for (int i = 0; i < size; i++){
				arr[i] = temp[i];
			}
			for (int i = size; i < (size + a.size); i++){
				arr[i] = a.arr[i - size];
			}
			size = size + a.size;
			delete[] temp;
			return *this;
		}
	}
	array& operator-(int a)
	{
		int flag;
		do{
			flag = 0;
			for (int i = 0; i < size; i++){
				if (arr[i] == a){
					flag = 1;
					int* temp=new int[size - 1];
					for (int j = 0; j < size; j++){
						if (j < i){
							temp[j] = arr[j];
						}
						else if (j > i){
							temp[j-1] = arr[j];
						}
					}
					delete[] arr;
					arr = new int[--size];
					for (int j = 0; j < size; ++j){
						arr[j] = temp[j];
					}
					delete[] temp;
					break;
				}
			}
		} while (flag == 1);
		return *this;
	}
		array& operator++()
	{
		int* temp=new int[size];
		for (int i = 0; i < size; i++){
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = new int[++size];
		for (int i = 0; i < size; i++){
			arr[i] = temp[i];
		}
		arr[size - 1] = 0;
		delete[] temp;
		return *this;
	}
	array& operator--()
	{
		int* temp=new int[size - 1];
		for (int i = 0; i < size - 1; i++){
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = new int[--size];
		for (int i = 0; i < size; i++){
			arr[i] = temp[i];
		}
		delete[] temp;
		return *this;
	}
	void print()
	{
		if (size){
			for (int i = 0; i < size; i++){
				cout << setw(3) << arr[i];
			}
			cout << endl;
		}
		else{
			cout << "No elements\n";
		}
	}
private:
	int* arr;
	int size;
};

int main()
{
	array A;
	array B(10);
	A.print();
	B.print();
	cout << B[5] << endl;
	B[5] = 5;
	cout << B[5] << endl;
	B = A;
    A.print();
	B.print();
	array C(5);
	A = C;
	A.print();
	B.print();
	C.print();
	cout << "____________________________\n";
	B = B + C;
	B.print();
	B = B + A;
	B.print();
	cout << "____________________________\n";
	cout << "Enter number\n";
	int a;
	cin >> a;
	B=B - a;
	B.print();
	cout << "____________________________\n";
	B++;
	B.print();
	B--;
	B.print();
	B--;
	B.print();
}