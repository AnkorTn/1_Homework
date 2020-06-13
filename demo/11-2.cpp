#include<iostream>
#include<cstring>
using namespace std;
class LongLongInt {
	friend ostream& operator<<(ostream &os, const LongLongInt& obj);
	private:
		char *s;
		int l;
	public:
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
	    	
			
			//cout<<"this->s="<<this->s<<endl;
	    	//cout<<"a1->s="<<a1.s<<endl;
	    	
	    	//cout<<"l1="<<l1<<endl;
	    	//cout<<"l2="<<l2<<endl;
	    	//cout<<"l3="<<l3<<endl;
	    	//cout<<"l4="<<l4<<endl;
	    	
	    	
	    	while(l1>=0&&l2>=0){
	    		ans[l4] += this->s[l1] + a1.s[l2] - '0';
	    		if(ans[l4]>'9'){	ans[l4-1] = 1;	ans[l4] -= 10;	} 	else ans[l4-1] = 0;
	    		
				
				//cout<<"s["<<l1<<"]="<<this->s[l1]<<"  and a1["<<l2<<"]= "<<a1.s[l2]<<endl; 
	    		//cout<<"Now by adding s["<<l1<<"] and a1["<<l2<<"] = ans["<<l4<<"]="<<ans[l4]<<endl; 
	    		
				
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
			LongLongInt answ(ans);
			
			
			//cout<<ans<<endl;
			
			
			delete[] ans;
			return answ;
		}
	    LongLongInt operator-(const LongLongInt &a1)const{
	    	int l1 = l-1, l2=a1.l-1;
	    	LongLongInt tmp(*this);
			
			//cout<<"this->s="<<tmp.s<<endl;
	    	//cout<<"a1->s="<<a1.s<<endl;
	    	//cout<<"l1="<<l1<<endl;
	    	//cout<<"l2="<<l2<<endl;
	    	
	    	
	    	while(l1>=0&&l2>=0){
	    		tmp.s[l1] += '0'- a1.s[l2];
	    		if(tmp.s[l1]<'0'){	tmp.s[l1-1]--;	tmp.s[l1]+=10;	}	    		
	    		
				
				//cout<<"s["<<l1<<"]="<<tmp.s[l1]<<"  and a1["<<l2<<"]= "<<a1.s[l2]<<endl; 
	    		//cout<<"Now by minus s["<<l1<<"] and a1["<<l2<<"] = ans["<<l1<<"]="<<tmp.s[l1]<<endl; 
	    		
				
				l1--;l2--;
			}
			int left=0; while((tmp.s[left] == '0'&&left<l&&tmp.s[left+1] == '0')||tmp.s[left] == 0) left++;	if(left>0)left--;
			for(int i=left; i<l; i++)	tmp.s[i-left] = tmp.s[i];	tmp.s[l-left] = '\0';
			//cout<<s<<endl;	
			//cout<<"left="<<left<<endl;
			//cout<<"l="<<l<<endl;
			//cout<<tmp.s<<endl;
			//cout<<strlen(tmp.s)<<endl;
			tmp.l=strlen(tmp.s);		
			return tmp;
		}
		~LongLongInt(){
			cout<<"delete longlongint:"<<s<<endl;
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
typedef LongLongInt ll;
int main(){
	char s[1000];
	cin>>s;
	ll a(s);
	cin>>s;
	ll c(s);
	ll b=a+c;
	cout<<(a+c)<<endl;
	cout<<"type1"<<1<<endl;
	cout<<(c-a)<<endl;
	cout<<"type2"<<2<<endl;
	cout<<b<<endl;
	//cin>>s;
	//ll b(s);
	//cout<<b<<endl;
	//ll b = c-a;
	//cout<<b<<endl;
	//cout<<c<<endl;
	return 0;
} 
