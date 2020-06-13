#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int chi;
	int math;
	int eng;
	int tot;
}s[1200];
bool cmp(student a, student b){
	if(a.tot !=b.tot)  return a.tot >b.tot;
	if(a.chi !=b.chi)  return a.chi >b.chi;
	if(a.math!=b.math) return a.math>b.math;
	if(a.eng !=b.eng)  return a.eng >b.eng;
	return a.name<b.name;
}
int main(){
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].name>>s[i].chi>>s[i].math>>s[i].eng;
		s[i].tot = s[i].chi+s[i].math+s[i].eng;
	}
	cin>>k;
	sort(s,s+n,cmp);
	cout<<s[k-1].name<<" "<<s[k-1].tot;
	return 0;
}
