#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

class Matrix
{
public:
	Matrix()
	{
		N = 10;
		matrix = new int*[10];
		for (int i = 0; i < 10; i++){
			matrix[i] = new int[10];
		}
		for (int i = 0; i<10; i++){
			for (int j = 0; j<10; j++){
				matrix[i][j] = 0;
			}
		}
	}
	Matrix(int _N) :N(_N)
	{
		matrix = new int*[N];
		for (int i = 0; i < N; i++){
			matrix[i] = new int[N];
		}
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				matrix[i][j] = rand() % 20;
			}
		}
	}
	Matrix(int _N, int mem) :N(_N)
	{
		matrix = new int*[N];
		for (int i = 0; i < N; i++){
			matrix[i] = new int[N];
		}
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				matrix[i][j] = mem;
			}
		}
	}
	Matrix(const Matrix& m2)
	{
		N = m2.N;
		matrix = new int*[N];
		for (int i = 0; i < N; i++){
			matrix[i] = new int[N];
		}
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				matrix[i][j] = m2.matrix[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i<N; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void Show(){
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				cout << setw(2) << setfill('0') << matrix[i][j] << " ";;
			}
			cout << endl;
		}
		cout << endl<<endl;
	}
	Matrix& operator=(const Matrix& m2)
	{
		if (this == &m2)
			return *this;
		else{
			if (N == m2.N){
				for (int i = 0; i < N; i++){
					for (int j = 0; j < N; j++){
						matrix[i][j] = m2.matrix[i][j];
					}
				}
				return *this;
			}
			else{
				for (int i = 0; i<N; i++)
					delete[] matrix[i];
				delete[] matrix;
				N = m2.N;
				matrix = new int*[N];
				for (int i = 0; i < N; i++){
					matrix[i] = new int[N];
				}
				for (int i = 0; i < N; i++){
					for (int j = 0; j < N; j++){
						matrix[i][j] = m2.matrix[i][j];
					}
				}
				return *this;
			}
		}
	}
	Matrix operator+(const Matrix& m2)
	{
		Matrix Res(N, 0);
		if (N != m2.N){
			cout << "Matrix size error!!!\n";
		return Res;
		}
		else{
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					Res.matrix[i][j] =matrix[i][j]+m2.matrix[i][j];
				}
			}
			return Res;
		}
	}
	Matrix operator*(const Matrix& m2)
	{
		Matrix Res(N, 0);
		if (N != m2.N){
			cout << "Matrix size error!!!\n";
			return Res;
		}
		else{
			for (int i = 0; i < N;i++){
				for (int j = 0; j < N; j++){
					for (int k = 0; k < N; k++){
						Res.matrix[i][j] +=matrix[i][k]*m2.matrix[k][j] ;
					}
				}
			}
			return Res;
		}
	}
	int& operator()(int n,int m)
	{
		return *(&matrix[n][m]);
	}
	Matrix Transp()
	{
		Matrix Res(N, 0);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				Res.matrix[i][j] = matrix[j][i];
			}
		}
		return Res;
	}
private:
	int N;
	int** matrix;
};

int main()
{
	srand(time(NULL));
	Matrix A;
	A.Show();
	Matrix B(5);
	B.Show();
	A = B;
	A.Show();
	A = A + B;
	A.Show();
	Matrix C(2);
	C.Show();
	Matrix D(2);
	D.Show();
	A = C*D;
	A.Show();
	cout << A(0,1)<<endl<<endl;
	A(0, 1) = 3;
	A.Show();
	A=A.Transp();
	A.Show();
}