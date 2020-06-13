#include <iostream>
#include<cstring>

using namespace std;

class LongLongInt {
  	friend ostream &operator<<(ostream &os,const LongLongInt x);
  private:
  	char num[200];

  public:
  	//这里我加了一个()是因为如果你直接定义一个变量啥都没有写，例如LongLongInt x；那程序不知道找哪个函数来构造初始化 
  		LongLongInt(){ }
      LongLongInt(const char * num0)
        {
   			int i,len=strlen(num0);
      		for(i=0;i<200-len;i++)
              num[i]='0';
            for(i=0;i<len;i++){
                num[200-len+i]=num0[i];
            }
        };

    LongLongInt(const LongLongInt& lli)
        {
   			int i;
            for(i=0;i<200;i++){
                num[i]=lli.num[i];
            }
        };
  LongLongInt operator-(const LongLongInt &b)
  {
  	char m[200],a[200],k[200];
    for(int i=0;i<200;i++)
    {
        a[i]=num[i];
        k[i]=b.num[i];
    }
    int i,temp;
        for(i=199;i>=0;i--)
        {
            temp=int(a[i])-int(k[i]);
            if(temp<0)
            {
                a[i-1]--;
                m[i]=char(temp+10+'0');
            }
            else
                m[i]=char(temp+'0');
        }
        char u[201];
        for(int j=0; j<200; j++)
            u[j]=m[j];
        u[200]='\0';
        LongLongInt sub(u);
    	return sub;
  }

 	LongLongInt operator+(const LongLongInt &b)
        {
            char s[200];
      		int flag=0,temp;
			for(int i=199;i>=0;i--)
            {
            	temp=int(num[i]-'0'+b.num[i]-'0'+flag);
              	flag=0;
              if(temp>=10)
                {
                	flag=1;
                  	s[i]=char(temp-10+'0');
                }
              	else
                {
                	s[i]=char(temp+'0');
                }
            }
            char t[201];
            for(int j=0; j<200; j++)
                t[j]=s[j];
            t[200]='\0';
           LongLongInt lli(t);
           return lli;
        }




    // overload +, - and << (for output)
};
 ostream &operator<<(ostream &os,const LongLongInt x)
    {
    	int i=0;
        while (x.num[i] == '0'&&i<=199)
            i++;
   		if(i==200)
          os<<0;
        while (i<=199)
            { os << x.num[i];
                  i++;
            }
        return os;
    }
class longlongintcomplex
{
	//需要友元去声明的函数应该就只有输入输出，其他的应该可以不需要 
	longlongintcomplex operator+(longlongintcomplex r1);
friend ostream &operator<<(ostream &os,const longlongintcomplex x);
LongLongInt real;
//然后你变量使用有点问题，这里用image后面有地方用imag，容易出错 
LongLongInt imag;
public:
	//这里是一个难点，就你一声明一个新的类的变量的时候，推荐立即初始化 ，而不是后面再临时real(a)，虽然我不知道有什么问题 
    longlongintcomplex(const char *a,const char *b){real=LongLongInt(a);imag=LongLongInt(b);};
};
longlongintcomplex longlongintcomplex::operator+(longlongintcomplex r1)
{
	//这里一样的，因为你没有对复数类进行初始化，所以我这里加了一下初始化
	//或者你在原本的类里面初始化也可以 
    longlongintcomplex tmp("0","0");
    tmp.real = real + r1.real;
    tmp.imag = imag + r1.imag;
    return tmp;
}
ostream &operator<<(ostream &os,const longlongintcomplex x)
{
    cout<<x.real<<"+"<<x.imag<<"i";
    return os;
}

int main()
{
    longlongintcomplex r1("1234","11"),r2("9876","22"),r3;
    cout<<"r1="<<r1<<endl;
    cout<<"r2="<<r2<<endl;
    r3=r1+r2;
    cout<<"r3=r1+r2="<<r3<<endl;
    return 0;
}

