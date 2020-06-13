#include <iostream>
#include <cstring>
using namespace std;

void del(char str[],char ch)
{
    int i=-1,k=0;
    while (str[++i] != '\0')
        if (str[i]!=ch) str[k++]=str[i];
    str[k]='\0';
}

int main()
{
    int n,i,j,index[30],tmp;
    bool flag;
    char *str[30],ch;
    cin >> n;
    for (i=0;i<n;i++)
        index[i]=i;
    for (i=0;i<n;i++)
    {
        str[i] = new char[31];
        cin >> str[i];
    }
    cin >> ch;
    for (i=0;i<n;i++)
        del(str[i],ch);
    for (i=1;i<n;i++)
    {
        flag = 0;
        for (j=0;j<n-i;j++)
            if (strcmp(str[index[j+1]],str[index[j]])>0){
                tmp=index[j];index[j]=index[j+1];index[j+1]=tmp;
                flag=1;
            }
        if (!flag) break;
    }
    for (i=0;i<n;i++){
        tmp=index[i];
        cout << str[tmp] << endl;
        delete str[tmp];
    }
    return 0;
}
