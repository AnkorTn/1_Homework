#include <iostream>
#include<cstring>

using namespace std;

class LongLongInt {
  	friend ostream &operator<<(ostream &os,const LongLongInt x);
  private:
  	char num[200];

  public:
  	//�����Ҽ���һ��()����Ϊ�����ֱ�Ӷ���һ������ɶ��û��д������LongLongInt x���ǳ���֪�����ĸ������������ʼ�� 
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
	//��Ҫ��Ԫȥ�����ĺ���Ӧ�þ�ֻ�����������������Ӧ�ÿ��Բ���Ҫ 
	longlongintcomplex operator+(longlongintcomplex r1);
friend ostream &operator<<(ostream &os,const longlongintcomplex x);
LongLongInt real;
//Ȼ�������ʹ���е����⣬������image�����еط���imag�����׳��� 
LongLongInt imag;
public:
	//������һ���ѵ㣬����һ����һ���µ���ı�����ʱ���Ƽ�������ʼ�� �������Ǻ�������ʱreal(a)����Ȼ�Ҳ�֪����ʲô���� 
    longlongintcomplex(const char *a,const char *b){real=LongLongInt(a);imag=LongLongInt(b);};
};
longlongintcomplex longlongintcomplex::operator+(longlongintcomplex r1)
{
	//����һ���ģ���Ϊ��û�жԸ�������г�ʼ�����������������һ�³�ʼ��
	//��������ԭ�����������ʼ��Ҳ���� 
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

