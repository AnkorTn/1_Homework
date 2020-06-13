#include<iostream>
#include<cstring>
using namespace std;
struct Integer{
	char num[10000];
	int len;
	void read(){
		cin>>num;
		len = strlen(num);
	}
	void write(){
		cout<<num<<endl;
	}
};
Integer add(Integer x, Integer y){
	Integer ans;
	int nx[300]={0}, ny[300]={0}, lx=x.len, ly=y.len;
	for(int i=0;i<lx;i++)	nx[lx-i-1] = x.num[i]-'0';
	for(int i=0;i<ly;i++)	ny[ly-i-1] = y.num[i]-'0';
	int lmax = lx>ly?lx:ly;
	for(int i=0;i<lmax;i++){	nx[i]+=ny[i];	nx[i+1]+=nx[i]/10;	nx[i]%=10; 	}
	while(!nx[lmax])lmax--;
	ans.len=lmax+1;
	ans.num[lmax+1] = '\0';
	for(int i=lmax;i>=0;i--)
		ans.num[lmax-i] = '0' + nx[i] ;
	return ans;
}
int main(){
	Integer a,b;
	a.read();
	b.read();
	add(a,b).write();
	return 0;
}
