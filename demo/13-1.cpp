#include<bits/stdc++.h>
using namespace std;
template <class T>
class mystack {
    private:
		T *p;		//array
		int scale;	//the largest scale
		int point;	//the pointer at the exact place
	public:
		mystack(int x = 100){
			scale = x;
			p = new T [scale];
			point = 0;
		}
		void push(int x){
			if(point == scale){
				T *x = new T[scale];
				for(int i=0;i<scale;i++)
					x[i] = p[i];
				delete []p;
				p = new T[scale*2];
				for(int i=0;i<scale;i++)
					p[i] = x[i];
				scale *= 2;
				delete []x;			
			} 
			p[point] = x;
			point++;
		}
		T pop(){
			T x = p[point-1];
			point--;
			return x;
		}
		bool isEmpty(){
			if(point == 0)	return true;
			return false;
		}
		~mystack(){
			delete []p;
		}
	 
};
int main(){
    mystack<char>stCh(4); //栈的初始规模为4
    for(int i=0;i<10;i++)    
		stCh.push('a'+i);
    while(!stCh.isEmpty()) 
		cout<<stCh.pop()<<' ';
    cout<<endl;
    mystack<int>stint(4);
    for(int i=0;i<6;i++)      
		stint.push(i*i);
    while(!stint.isEmpty()) 
		cout<<stint.pop()<<' ';
    cout<<endl;
    return 0;
}
