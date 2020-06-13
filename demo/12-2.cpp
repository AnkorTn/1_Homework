#include<bits/stdc++.h>
using namespace std;
/*
，用一个动态整型数组存放栈的数据，
数据成员包括指向动态数组的指针，
栈的最大规模（缺省值为100）和栈顶指针，
要求能够判别栈满和栈空，数据进栈函数push，出栈函数pop
*/
class mystack {
    private:
		int *p;		//array
		int scale;	//the largest scale(set =100)
		int point;	//the pointer at the exact place
	public:
		mystack(int x = 100){
			scale = x;
			p = new int [scale];
			point = 0;
		}
		bool push(int x){
			if(point == scale)	return false;
			p[point] = x;
			point++;
			return true;
		}
		bool pop(int &x){
			if(point == 0)	return false;
			x = p[point-1];
			point--;
			return true;
		}
		bool isempty(){
			if(point == 0)	return true;
			return false;
		}
		bool isfull(){
			if(point == scale)	return true;
			return false;
		}
		~mystack(){
			delete []p;
		}
	 
};
int main(){
    int num[]={1,3,5,7,9,11},i,data;
    mystack s(5);
    cout<<"The stack is empty: "<<s.isempty()<<endl;
    cout<<"The stack is full: "<<s.isfull()<<endl;
    for(i=0;i<=5;i++){
        if(s.push(num[i]))
            cout<<"Push "<<num[i]<<" success!"<<endl;
        else
            cout<<"Push "<<num[i]<<" fail!"<<endl;
    }
    cout<<"The stack is empty: "<<s.isempty()<<endl;
    cout<<"The stack is full: "<<s.isfull()<<endl;
    for(i=0;i<=5;i++){
        if(s.pop(data))
            cout<<"Pop "<<data<<" success!"<<endl;
        else
            cout<<"Pop fail!"<<endl;
    }
    return 0;
}
