#include<bits/stdc++.h>
using namespace std;
int main(){
	float temp;
	int op;
	cin>>op;
	while(op){
		cin>>temp;
		cout<<temp<<endl;
		int tmp = temp*1000;
		cout<<tmp<<endl;
		if(tmp%10>=5)
			tmp += 10;
		cout<<tmp<<endl;
		tmp /= 10;
		temp = tmp/100.0;
		printf("printf=%.2f\n",temp);
		cout<<temp<<endl<<"op=";
		cin>>op;
		//cout<<temp<<endl;
	}
	
	return 0;
}
