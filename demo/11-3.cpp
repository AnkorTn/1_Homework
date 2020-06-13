#include<bits/stdc++.h>
#include<cmath>
using namespace std;
class MyVect {
	friend ostream& operator<<(ostream &os, const MyVect& obj);
	friend istream& operator>>(istream &input,MyVect &obj);
	private:
		int n;
		int *vec;
		double norm;
		static int count;
		static int living;
		
	public:
		//Initialization. Construction
		MyVect(int x){
			n = x;
			vec = new int[n];
			living++;
			count++;
		}
		MyVect(const MyVect &a){
			n = a.n;
			vec = new int[n];
			for(int i = 0; i < n; i++)
				vec[i] = a.vec[i];
			living++;
			count++;
		}
		
		
		//Get_data
		int getlength(){	return n;		}
		double getnorm(){	return norm;	}
		static int getcount(){		return count;	}
		int getliving(){	return living;	}
		
		
		//Operator modification
		double operator-(const double x)const{
			return norm - x;
		}
		MyVect operator+(const MyVect &a)const{
			MyVect tmp(max(n,a.n));
			for(int i = 0; i < tmp.n; i++){
				if(i<n&&i<a.n)	tmp.vec[i] = vec[i] + a.vec[i];
				else if(i<a.n)	tmp.vec[i] = a.vec[i];
				else			tmp.vec[i] = vec[i];
			}
			return tmp;
		}
		MyVect &operator=(const MyVect &a){
		    if(this == &a) return *this;
		    n = a.n;
		    delete[]vec;
		    vec = new int[n];
			for(int i = 0; i < n; i++)
				vec[i] = a.vec[i];
			return *this;
		}
		int &operator[](int x){
			return vec[x];
		}
		const int&operator[](int x)const{
			return vec[x];
		}
		bool operator==(const MyVect &a){
			if(n!=a.n)	return false;
			for(int i = 0; i < n; i++)
				if(vec[i] != a.vec[i])
					return false;
			return true;
		}	
		//prefix
		MyVect &operator++(){
			for(int i = 0; i < n; i++)
				vec[i]++;
			return *this;
	    }
	    
    	MyVect operator++(int){
    		MyVect tmp = *this;
    		for(int i = 0; i < n; i++)
				vec[i]++;
			return tmp;
    	}
		
		
		//Destruction
		~MyVect(){
			delete[]vec;
			living--;
		}
	
	 
};
ostream& operator<<(ostream &os, const MyVect& obj){
	for(int i = 0; i < obj.n-1; i++)
		os<<obj.vec[i]<<" ";
	os<<obj.vec[obj.n-1];
	return os;
}
istream& operator>>(istream &is,MyVect &obj){
	obj.norm = 0;
	for(int i = 0; i < obj.n; i++){
		is>>obj.vec[i];
		obj.norm += obj.vec[i]*obj.vec[i];
	}
	obj.norm = sqrt(obj.norm);
  	return is;
}
int MyVect::count = 0;
int MyVect::living = 0;
int main(){
    MyVect v1(5);
    double x;
    cin >> v1;
    cout << "Now v1 is: "<< v1 << endl;
    cout << "The length of v1 is " << v1.getlength() << endl;
    cout << "The norm of v1 is " << v1.getnorm() << endl;
    x = v1 - 1.0;
    cout << "The norm of v1 minus 1 is " << x << endl;
    MyVect v2 = v1;
    cout << "Now v2 is: " << v2 << endl;
    cout << "The number of vectors is: " << v1.getcount() << endl;
    cout << endl;
    {
        MyVect v3(5);
        v3= v1 + v2;
        cout << "The result of v1+v2 is: " << v3 << endl;
        cout << "The 1st element of v3 is " << v3[1] << endl;
        cout << "The number of vectors is: " << MyVect::getcount() << endl;
    }
    cout << endl;
    cout << "The number of living vectors is: " << v1.getliving() << endl;
    cout << "The number of total vector is: " << v1.getcount() << endl;
    cout << "The result of v1++ is: " << v1++ << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    cout << "The result of ++v2 is: " << ++v2 << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    return 0;
}
