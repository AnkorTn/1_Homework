#include<bits/stdc++.h>
using namespace std;
class longlongint {
	friend ostream& operator<<(ostream &os, const longlongint& obj);
	private:
		char *s;
		int l;
	public:
    	longlongint(const char *num){
	    	l = strlen(num);
	    	s = new char[l+1];
	    	for(int i=0;i<l;i++)
	    		s[i] = num[i];
	    	s[l] = '\0';
		}
	    longlongint(const longlongint &other){
	    	this->l = other.l;
	    	s = new char[this->l+1];
    		for(int i=0;i<this->l;i++)
	    		this->s[i] = other.s[i];
	    	this->s[l] = '\0';
		}
	    // overload +, - and << (for output)
	    longlongint operator+(const longlongint &a1)const{
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
			int left=0; while((ans[left] == '0'&&left<l3&&ans[left+1]=='0')||ans[left] == 0) left++;
			for(int i=left; i<l3; i++)	ans[i-left] = ans[i];	ans[l3-left] = '\0';
			longlongint answ(ans);
			delete[] ans;
			return answ;
		}
	    longlongint operator-(const longlongint &a1)const{
	    	int l1 = l-1, l2=a1.l-1;
	    	longlongint tmp(*this);
	    	while(l1>=0&&l2>=0){
	    		tmp.s[l1] += '0'- a1.s[l2];
	    		if(tmp.s[l1]<'0'){	tmp.s[l1-1]--;	tmp.s[l1]+=10;	}	    		
				l1--;l2--;
			}
			int left=0; while((tmp.s[left] == '0'&&left<l&&tmp.s[left+1] == '0')||tmp.s[left] == 0) left++;	if(left>0)left--;
			for(int i=left; i<l; i++)	tmp.s[i-left] = tmp.s[i];	tmp.s[l-left] = '\0';
			tmp.l=strlen(tmp.s);		
			return tmp;
		}
		bool operator==(const longlongint lt)const{
    		if(l!=lt.l)	return false;
    		for(int i = 0; i < l; i++)
    			if(s[i] != lt.s[i])
    				return false;
    		return true;
		}
		~longlongint(){
			//delete[]s;
		}
};
ostream& operator<<(ostream &os, const longlongint& obj){
	int i=0, l=strlen(obj.s);
	while(obj.s[i]=='0'&&i<l)	i++;
	if(i==l) os<<"0";
	else for(;i<l;i++)os<<obj.s[i];
   	return os;
}
class longlongintcomplex{
	friend ostream& operator<<(ostream &os, const longlongintcomplex& obj);
	private:
		longlongint real;
		longlongint imag;
	public:
		longlongintcomplex(longlongint a="0", longlongint b="0"):real(a),imag(b){}
		longlongintcomplex operator+(const longlongintcomplex &a1)const{
			longlongint r = real+a1.real;
			longlongint i = imag+a1.imag;
			longlongintcomplex ans(r,i);
			return ans;
		}
		~longlongintcomplex(){
			//cout<<"Now ~longlongintcomplex is being destructed:"<<real<<"+"<<imag<<"i"<<endl;
		}
		
};
ostream& operator<<(ostream &os, const longlongintcomplex& obj){
	longlongint tmp("0");
	if(obj.real==tmp){
		if(obj.imag==tmp)
			os<<"0";
		else
			os<<obj.imag<<"i";
	}
	else{
		if(obj.imag==tmp)
			os<<obj.real;
		else
			os<<obj.real<<"+"<<obj.imag<<"i";
	}
   	return os;
}
int main(){
    longlongintcomplex r1("1234","11"),r2("9876","22"),r3;
    cout<<"r1="<<r1<<endl;
    cout<<"r2="<<r2<<endl;
    r3=r1+r2;
    cout<<"r3=r1+r2="<<r3<<endl;
    return 0;
}

