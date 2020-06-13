#include <iostream>
#include <cstring>
using namespace std;
char *&funA(char **&p){
	p = new char*;
	return *p;
}
char *funB(char *b, char **&p){
	static int tmp=0;
	int r=strlen(*p),l=0;
	while(l<r){
		if((*(*p+l)>='a')&& (*(*p+l)<='z'))
			b[l] = *(*p+l) -('a'-'A');
		else
			b[l] = *(*p+l);
		l++;
	}
	b[l] = '\n';
	b[l+1]='\0';
	if(tmp==3)
		delete p;
	tmp++;
	return b;
}
// 写出两个函数的声明
int main() {
	char a[100], b[100];
	for(int i = 0; i < 3; ++i) {
		char **p;
		cin >> a;
		funA(p) = a;
		cout << funB(b, p);
	}
	return 0;
}
