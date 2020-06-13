#include<bits/stdc++.h>
using namespace std;
#include<cstring>
class LongLongInt {
	friend ostream& operator<<(ostream &os, const LongLongInt& obj);
	public:
		char *s;
		int l;
		LongLongInt(){};
    	LongLongInt(const char *num){
	    	l = strlen(num);
	    	s = new char[l+1];
	    	for(int i=0;i<l;i++)
	    		s[i] = num[i];
	    	s[l] = '\0';
		}
	    LongLongInt(const LongLongInt &other){
	    	this->l = other.l;
	    	s = new char[this->l+1];
    		for(int i=0;i<this->l;i++)
	    		this->s[i] = other.s[i];
	    	this->s[l] = '\0';
		}
	    // overload +, - and << (for output)
	    LongLongInt operator+(const LongLongInt &a1)const{
	    	int l1 = l-1, l2=a1.l-1, l3 = max(l1,l2)+2, l4 = l3-1;
	    	char *ans = new char[l3];   	ans[l4] = 0;
	    	while(l1>=0&&l2>=0){
	    		ans[l4] += this->s[l1] + a1.s[l2] - '0';
	    		if(ans[l4]>'9'){	ans[l4-1] = 1;	ans[l4] -= 10;	} 	else ans[l4-1] = 0;
				l1--;l2--;l4--;
			}
			while(l1>=0){
				ans[l4] += this->s[l1];
				if(ans[l4]>'9'){	ans[l4-1] = 1;	ans[l4] -= 10;	} 	else ans[l4-1] = 0;
				l1--; l4--;
			}
	    	while(l2>=0){
				ans[l4] += a1.s[l2];
				if(ans[l4]>'9'){	ans[l4-1] = 1;	ans[l4] -= 10;	} 	else ans[l4-1] = 0;
				l2--; l4--;
			}
			if(ans[l4] == 1) ans[l4] = '1';	if(ans[l4] == 0) ans[l4] = '0';
			int left=0; while(ans[left] == '0'||ans[left] == 0) left++;
			for(int i=left; i<l3; i++)	ans[i-left] = ans[i];	ans[l3-left] = '\0';
			LongLongInt answ(ans);
			delete[] ans;
			return answ;
		}
	    LongLongInt operator-(const LongLongInt &a1)const{
	    	int l1 = l-1, l2=a1.l-1;
	    	LongLongInt tmp(*this);
	    	while(l1>=0&&l2>=0){
	    		tmp.s[l1] += '0'- a1.s[l2];
	    		if(tmp.s[l1]<'0'){	tmp.s[l1-1]--;	tmp.s[l1]+=10;	}	    		
				l1--;l2--;
			}
			int left=0; while(tmp.s[left] == '0'||tmp.s[left] == 0) left++;	if(left>0)left--;
			for(int i=left; i<l; i++)	tmp.s[i-left] = tmp.s[i];	tmp.s[l-left] = '\0';
			tmp.l=strlen(tmp.s);		
			return tmp;
		}
		~LongLongInt(){
			delete[]s;
		}
};
ostream& operator<<(ostream &os, const LongLongInt& obj){
	int i=0, l=strlen(obj.s);
	while(obj.s[i]=='0'&&i<l)	i++;
	if(i==l) os<<"0";
	else for(i;i<l;i++)os<<obj.s[i];
   	return os;
}
class signLLI:public LongLongInt{
    // MUST inherit LongLongInt
	friend ostream& operator<<(ostream &os, const signLLI& obj);
    public:
    	bool sign;
    	signLLI(const char *num){
	    	l = strlen(num);
	    	if(num[0]=='-'){
	    		sign = 1;
	    		s = new char[l+1];
	    		for(int i=0;i<l;i++)
	    			s[i] = num[i+1];
			}		
			else{
				sign = 0;
				s = new char[l+1];
	    		for(int i=0;i<=l;i++)
	    			s[i] = num[i];
			} 
		}
		signLLI operator+(const signLLI &a1);
		signLLI operator-(signLLI &a1);
		bool operator<(const signLLI &obj);
		bool operator>(const signLLI &obj);
};
signLLI signLLI::operator+(const signLLI &a1){
	LongLongInt tmp1=*this,tmp2=a1;
	if(sign == a1.sign){
		signLLI tmp((tmp1+tmp2).s);
		tmp.sign = sign;
		return tmp;
	}
	else{
		if(sign==0&&a1.sign==1){
			if(*this<a1){
				signLLI tmp((tmp2-tmp1).s);
				tmp.sign = 1;
				return tmp;
			}
			else{
				signLLI tmp((tmp1-tmp2).s);
				tmp.sign = 0;
				return tmp;
			}
		}
		else{
			if(*this<a1){
				signLLI tmp((tmp2-tmp1).s);
				tmp.sign = 0;
				return tmp;
			}
			else{
				signLLI tmp((tmp1-tmp2).s);
				tmp.sign = 1;
				return tmp;
			}
		}
	}
}


signLLI signLLI::operator-(signLLI &a1){
	LongLongInt tmp1=*this,tmp2=a1;
	if(sign>a1.sign){
		signLLI tmp((tmp1+tmp2).s);
		tmp.sign = 1;
		return tmp;
	}
	else if (a1.sign>sign){
		signLLI tmp((tmp1+tmp2).s);
		tmp.sign = 0;
		return tmp;
	}
	else if(a1.sign==1){
		if(*this>a1){
			signLLI tmp((tmp1-tmp2).s);
			tmp.sign = 1;
			return tmp;
		}
		else{
			signLLI tmp((tmp2-tmp1).s);
			tmp.sign = 0;
			return tmp;
		}
	}
	else{
		if(*this<a1){
			signLLI tmp((tmp2-tmp1).s);
			tmp.sign = 1;
			return tmp;
		}
		else{
			signLLI tmp((tmp1-tmp2).s);
			tmp.sign = 0;
			return tmp;
		}
	}
}


bool signLLI::operator<(const signLLI &obj){
	if(l>obj.l)	return 0;
	else if(l<obj.l) return 1;
	else{
		for(int i=0;i<l;i++)
			if(s[i]>obj.s[i])return 0;
				else if(s[i]<obj.s[i])return 1;
		return 0;
	}
}

bool signLLI::operator>(const signLLI &obj){
	if(l>obj.l)	return 1;
	else if(l<obj.l) return 0;
	else{
		for(int i=0;i<l;i++)
			if(s[i]>obj.s[i])return 1;
				else if(s[i]<obj.s[i])return 0;
		return 0;
	}
}


ostream& operator<<(ostream &os, const signLLI& obj){
	if(obj.sign==1)os<<"-";
	os<<obj.s;
   	return os;
}
int main(){
    signLLI a("123"),b("-123"),c("4067");
    cout<<a<<endl<<b<<endl<<c<<endl;
    cout<<"a-b=:"<<a-b<<endl;
    cout<<"a+a+a=:"<<a+a+a<<endl;
    cout<<"a-c=:"<<a-c<<endl;
    cout<<"b-a=:"<<b-a<<endl;
    cout<<a-b+a+a+a-c<<endl;
    return 0;
}
