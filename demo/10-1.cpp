#include<bits/stdc++.h>
using namespace std;
class Complex{
	private:
		//Êµ²¿real Ðé²¿imag 
		int real;
		int imag;
	public:
		Complex(int r=0, int i=0){
			real = r;
			imag = i;
		}
		void add(Complex x, Complex y){
			real = x.real + y.real;
			imag = x.imag + y.imag;
		}
		void display(){
			cout<<"(";
			if(real == 0){
				if(imag == 0)
					cout<<"0)";
				else
					cout<<imag<<"i)";
			}
			else{
				cout<<real;
				if(imag>0)
					cout<<"+"<<imag<<"i)";
				else if(imag<0)
					cout<<imag<<"i)";
				else
					cout<<")";	
			}	
		}
		
};
int main(){
	int ar, ai, br, bi, cr;
	cin >> ar >> ai >> br >> bi >> cr;
	Complex a(ar, ai), b(br, bi), c(cr), d;
	// a+b
	d.add(a, b);
	a.display();
	cout << " + ";
	b.display();
	cout << " = ";
	d.display();
	cout << endl;	
	// a+c
	d.add(a, c);
	a.display();
	cout << " + ";
	c.display();
	cout << " = ";
	d.display();
	cout << endl;
  	return 0;
}
