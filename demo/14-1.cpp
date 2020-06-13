#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream out("statistics.txt");
	ifstream in("article.txt");
	int paragraph = 0, letter = 0, word = 0, len, i;
	bool flag;
	while(!in.eof()){
		char ch[10001];
		in.getline(ch,10000);
		len = strlen(ch);
		i = 0;
		flag = false;
		while(i<len){
			if(ch[i]!=','&&ch[i]!='.'&&ch[i]!=' '&&ch[i]!='\n'){
				word++;
				flag = true;
				while(i<len&&ch[i]!=','&&ch[i]!='.'&&ch[i]!=' '&&ch[i]!='\n'){
					letter++;
					i++;
				}
			}
			else i++;
		}
		if(flag) paragraph++;
	}
	out<<paragraph<<endl;
	out<<word<<endl;
	out<<letter<<endl;
	out.close();
	in.close();
	return 0;
} 
