#include<bits/stdc++.h>
using namespace std;
// Define your struct here. Its name *must* be my_complex.
struct my_complex{
	long long real;
	long long imag;
};

/**
 * Read a complex number.
 * @return pointer to the complex number just read, allocated on heap
 */
my_complex *read_complex() {
	my_complex *tmp = new my_complex;
	cin>>tmp->real>>tmp->imag;
	return tmp;
}
/**
 * Add two complex numbers.
 * @return pointer to the result, allocated on heap
 */
my_complex *add_complex(const my_complex *a, const my_complex *b) {
	my_complex *tmp = new my_complex;
	tmp->real = a->real + b->real;
	tmp->imag = a->imag + b->imag;
	return tmp;
}

/**
 * Print a complex number.
 */
void print_complex(const my_complex *a) {
	cout<<a->real<<"+"<<a->imag<<"i"<<endl;
	return;
}
int main(){
	my_complex t1,t2,*x,*y;
	x = read_complex();
	//cout<<x->real<<x->imag<<endl;
	y = read_complex();
	x = add_complex(x,y);
	print_complex(x);
	//cout<<x->real<<x->imag<<endl;
	//cout<<y->real<<y->imag<<endl;
}
