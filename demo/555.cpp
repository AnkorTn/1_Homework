#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	string s[40],tmp;	char c;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	cin>>c; 
	for(int i=0;i<n;i++){
		int l=0,r=s[i].length();
		while(l < r){
			if(s[i][l]==c){
				for(int j=l;j<r-1;j++)
					s[i][j] = s[i][j+1];
				s[i][r-1] = '\0';
			}
			else
				l++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(s[i]<s[j]){
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
	return 0;
} 
