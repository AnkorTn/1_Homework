#include<bits/stdc++.h>
using namespace std;
class base{
	int data;
	public:
		base(int i=1){data = i;		}
		base operator+(const base &r)const{
			base tmp;
			tmp.data=r.data+data;
			return tmp;
		}
		base &operator=(const base &r){
			data=10*r.data;return *this;
		}
}; 
class derived:public base{
	int newdata;
	public:
	 	derived(int i=0,int j=0){
	 		newdata = j;
		 }
		derived &operator=(const derived &tmp){
			newdata =tmp.newdata * 2;
			base::operator=(tmp);
			return *this;
		}
		int getj(){
			return newdata;
		}
};
/*
class derived{
	friend derived operator+(const derived&t1,const derived&t2){
		derived tmp;tmp.n=t1.n+t2.n;return tmp;
	}
	private: base n;
	public:  derived(int i=0):n(i){}
};
*/
int main(){
	derived a(3,4),c(4,5),d;
	d=a;
	cout<<a.getj()<<"  "<<c.getj()<<"  "<<d.getj()<<endl;
	return 0;
}

