#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream out("f.txt");
	int i=0;
	for(i=1;i<=10;i++)out<<i<<" ";
	out.close();
	ifstream in("f.txt");
	while(!in.eof()){
		in>>i;
		cout<<i<<" ";
	}
	in.close();
	return 0;
}
