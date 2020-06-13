#include <iostream>
#include <cstring>

using namespace std;

bool compare(char a[],char b[])
{
    int lena,lenb,i;
    lena = strlen(a);
    lenb = strlen(b);
    if(lena>lenb){
        for(i=0;i<lenb;i++){
            if(a[i]>b[i]){return 1;}
            if(a[i]<b[i]){return 0;}
        }
        return 1;
    }
    else{
        for(i=0;i<lena;i++){
            if(a[i]>b[i]){return 1;}
            if(a[i]<b[i]){return 0;}
        }
        return 0;
    }
}       //比较两个字符串的字典序

int main()
{
    int n,i,j,k,len;
    cin>>n;
    char *str[n],ch,*temp;
    for(i=0;i<n;i++){
        str[i]=new char[31];
        cin>>str[i];
    }
    cin>>ch;
    for(i=0;i<n;i++){
        len=strlen(str[i]);
        k=0;
        for(j=0;j<len;j++){
            if(str[i][j]!=ch){
                str[i][k]=str[i][j];
                k+=1;}
        }
        str[i][k]=str[i][j];
    }     //去重
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(compare(str[i],str[j])==0){
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }       //冒泡排序

    for(i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
    return 0;
}

