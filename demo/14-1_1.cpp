#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;
struct students{
	char id[13];
	int chi;	int mat;	int eng;	int tot;	int num;
}student[10001];
bool cmp(students a, students b){
	if(a.tot == b.tot)	return a.num<b.num;
	return a.tot>b.tot;
}
int main(){
	ofstream out("final.txt");
	ifstream in("score.txt");
	int i=0;
	while(in>>student[i].id>>student[i].chi>>student[i].mat>>student[i].eng){
		student[i].tot = student[i].chi + student[i]. mat + student[i].eng;	student[i].num = i;	i++;
	}
	i--;
	sort(student,student+i+1,cmp); 
	/*students tmp;
	for(int j=i;j>=0;j--)
		for(int k=0;k<j;k++)
			if(student[k+1].tot>student[k].tot){
				tmp = student[k+1];
				student[k+1] = student[k];
				student[k] = tmp;
			}*/
	for(int j=0;j<=i;j++)
		out<<student[j].id<<" "<<student[j].chi<<" "<<student[j].mat<<" "<<student[j].eng<<" "<<student[j].tot<<endl;
	out.close();
	in.close();
	return 0;
}
