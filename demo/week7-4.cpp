#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char *p[30],*tmp,del;
	for(int i=0;i<n;i++){
		p[i] = new char[30];
		cin>>p[i];
	}
	cin>>del;
	
	for(int i=0;i<n;i++){
		int l=0,r=strlen(p[i]);
		while(l<r){
			if(p[i][l] == del)
				for(int j=l;j<r;j++)
					p[i][j] = p[i][j+1];
			else
				l++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(strcmp(p[j],p[i])>0){
				tmp = p[j];
				p[j] = p[i];
				p[i] = tmp;
			}
			
	for(int i=0;i<n;i++)
		cout<<p[i]<<endl;
	
	for(int i=0;i<n;i++)
		delete p[i];
	return 0;
} 



/*
int n;	cin>>n;
	char **p = new char*[n], str1[50], del;
	for(int i=0;i<n;i++){
		cin>>str1;
		p[i] = new char[strlen(str1)];
		p[i] = str1;
		for(int j=0;j<i;j++)
			cout<<p[i]<<endl;
	}
	cin>>del;
	for(int i=0;i<n;i++){
		cout<<p[i]<<endl;
		int l=0,r=strlen(p[i]);
		while(l<r){
			if(p[i][l] == del)
				for(int j=l;j<r;j++)
					p[i][j] = p[i][j+1];
			l++;
		}
		cout<<p[i]<<endl;
	}
	for(int i=0;i<n;i++)	delete []p[i];
	delete []p;
	return 0;
*/









	/*int n;	string s[40],tmp;	char c;
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
	return 0;*/
