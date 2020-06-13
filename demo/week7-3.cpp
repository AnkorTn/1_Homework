#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	cin>>n;
	char **p = new char*[n], str1[50], del;
	for(int i=0;i<n;i++){
		cin>>str1;
		p[i] = new char[strlen(str1)];
		p[i] = str1;
	}
	cin>>del;
	cout<<del;
	for(i=0;i<3;i++)	delete [] p[i];
	delete []p;
	return 0;
} 
