#include<bits/stdc++.h>
using namespace std;
class A{
	private:
		int x,y;
	public:
		A(int a=1,int b=1){
			x=a;y=b;
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
		~A(){
			cout<<"["<<x<<","<<y<<"]"<<endl;
		}
};
A e(0,0);
int main(){
	A a, *b = new A(3,4);
	{A c(-5,7);	}
	A d(1,2);
	delete b;
	return 0;
}
