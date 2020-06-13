#include<bits/stdc++.h>
using namespace std;
int main(){
	char info[100];
	cin>>info;
	int tmp = 0, l = strlen(info), i = 0, flag = 0;
	int year,month,day;
    		while(i<l){
    			tmp = 0;
    			while(info[i]!='-'&&i<l){
    				tmp += info[i]-'0';
    				tmp *= 10;
    				i++;
				}
				i++;
				switch(flag){
					case 0:
						year = tmp/10;
						flag++;
						break;
					case 1:
						month = tmp/10;
						flag++;
						break;
					default:
						day = tmp/10;
						break;
				}
			}
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}
