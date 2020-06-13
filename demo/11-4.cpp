#include<bits/stdc++.h>
using namespace std;
// Define and implement class Matrix
// Never write main() here
// There must be constructor and destructor
class Matrix {
	friend ostream& operator<<(ostream &os, const Matrix& obj);
	friend istream& operator>>(istream &input,Matrix &obj);
	private:
		int row;
		int column;
		int **p;
	public:
		Matrix(int m, int n){
			row = m;
			column = n;
			p = new int*[row];
			for(int i = 0; i < row; i++)
				p[i] = new int [column];
		}

		Matrix operator+(const Matrix &a1)const{
			Matrix ans(row,column);
			for(int i = 0; i < row; i++)
				for(int j = 0; j < column; j++)
					ans.p[i][j] = this->p[i][j] + a1.p[i][j];
			return ans;
		}

		Matrix &operator=(const Matrix &a1){
		    if(this == &a1) return *this;
		    row = a1.row;
		    column = a1.column;
		    for(int i = 0; i < row; i++)	delete[]p[i];	delete[]p;
		    p = new int*[row];
			for(int i = 0; i < row; i++)
				p[i] = new int [column];
			for(int i = 0; i < row; i++)
				for(int j = 0; j < column; j++)
					p[i][j] = a1.p[i][j];
			return *this;
		}

		int operator()(const int x, const int y){
			return p[x][y];
		}
		~Matrix(){
			for(int i = 0; i < row; i++)	delete[]p[i];	delete[]p;
		}
};
ostream& operator<<(ostream &os, const Matrix& obj){
	for(int i = 0; i < obj.row; i++){
		for(int j = 0; j < obj.column - 1; j++)
			os<<obj.p[i][j]<<" ";
		os<<obj.p[i][obj.column-1]<<endl;
	}
	return os;
}
istream& operator>>(istream &is,Matrix &obj){
	for(int i = 0; i < obj.row; i++)
		for(int j = 0; j < obj.column; j++)
			is>>obj.p[i][j];
  	return is;
}
int main(){
	int m, n, x, y;
	cin >> m >> n >> x >> y;
	//m->row,n->column
	Matrix a(m, n), b(m, n);
	cin >> a >> b;
	Matrix c = a+b;
	cout << c;
	a = b+c;
	// print element at row-x column-y of Matrix a, row and column count from 0
	cout << a(x, y) << endl; 
	return 0;
}
