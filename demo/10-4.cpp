#include<bits/stdc++.h>
using namespace std; 
class LongLongInt {
    private:
        char *num;
    public:
        LongLongInt(char * num){
			int len = strlen(num);
			this->num = new char[len + 1];
			for(int i=0;i<len;i++)
				this->num[i] = num[i];
			this->num[len] = '\0';
        };

        LongLongInt(const LongLongInt& lli){
			int len = strlen(lli.num);
			this->num = new char[len + 1];
			for(int i=0;i<len;i++)
				this->num[i] = lli.num[i];
			this->num[len] = '\0';
        };
        /*
		void display(){
            int i=-1;
            while (num[++i]!='\0')
                cout << num[i];
        };
		*/
        void display(){
			cout<<num<<endl;
        };
        
        LongLongInt add(LongLongInt b){
			int lena = strlen(this->num);	int lenb = strlen(b.num);
			int flag = 0, tot = 0;
			char *ans = new char[max(lena,lenb) + 2];
			char *numa = new char[lena];
			char *numb = new char[lenb];
			for(int i=0;i<lena;i++)
				numa[i] = this->num[lena-i-1];
			for(int i=0;i<lenb;i++)
				numb[i] = b.num[lenb-i-1];
			LongLongInt a1(numa), a2(numb);
			while(tot<lena && tot<lenb){
				if(!flag) ans[tot] = 0;
				else{	ans[tot] = 1;	flag = 0;	} 
				ans[tot] += a1.num[tot] + a2.num[tot] - '0';
				if(ans[tot]>'9'){	ans[tot] -= 10;	flag = 1;	}
				tot++;
			}
			while(tot<lena){
				if(!flag) ans[tot] = 0;
				else{	ans[tot] = 1;	flag = 0;	} 
				ans[tot] += a1.num[tot];
				if(ans[tot]>'9'){	ans[tot] -= 10;	flag = 1;	}
				tot++;
			}
			while(tot<lenb){
				if(!flag) ans[tot] = 0;
				else{	ans[tot] = 1;	flag = 0;	} 
				ans[tot] += a2.num[tot];
				if(ans[tot]>'9'){	ans[tot] -= 10;	flag = 1;	}
				tot++;
			}
			if(flag == 1){	ans[tot] = '1';	tot++;	} 
			while(ans[tot-1] == '0'&& tot>0) tot--;

			char *tmp = new char[tot+2];
			for(int i=0;i<tot;i++)
				tmp[i] = ans[tot-i-1];
			tmp[tot] = '\0';
			LongLongInt answ(tmp);
			delete []ans;
			delete []numa;
			delete []numb;
			delete []tmp;
			return answ;
        }
};
int main(){
	char *p = new char[5];
	cin>>p;
	char *q = new char[4];
	cin>>q;
	LongLongInt a(p);
	LongLongInt b(q);
	LongLongInt c=a.add(b);
	c.display();
	return 0;
}
