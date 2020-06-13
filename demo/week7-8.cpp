#include <bits/stdc++.h>
using namespace std;
// [IN] char* a, char* b: positive float number represented as string
// [OUT] char* res: result of a + b represented as string
void add_float(char* a, char* b, char* res) {
	int point1 = 0, point2 = 0, r1, r2, ant = 0;
	bool flag = 0;
	r1 = strlen(a);r2 = strlen(b);
	while(a[point1]!='.')point1++;	r1 = strlen(a);
	while(b[point2]!='.')point2++;	r2 = strlen(b);
	char *integer = new char[300], *flo = new char[300], *ans = new char[300];
	for(int i=0;i<300;i++){	integer[i] = 0;	flo[i] = 0;	}
	
	int ll1=r1-1-point1, ll2=r2-1-point2, tot = 0;	int lll = max(ll1,ll2);
	while(ll1>0&&ll2>0){
		if(lll<=ll1&&lll<=ll2){	flo[lll] +=(a[ll1+point1]+b[ll2+point2]-'0');	ll1--;ll2--;}
			else if(lll>ll1){	flo[lll] += b[ll2+point2];ll2--;	}
				else{			flo[lll] += a[ll1+point1];ll1--;	}
		if(flo[lll]>'9'){	flo[lll]-=10;	flo[lll-1]++;	}
		ans[ant++] = flo[lll];
		lll--;
	}
	while(ll1>0){
		flo[lll] +=a[ll1+point1];	ll1--;
		ans[ant++] = flo[lll];
		lll--;
	}
	while(ll2>0){
		flo[lll] +=b[ll2+point2];	ll2--;
		ans[ant++] = flo[lll];
		lll--;
	}
	if(flo[lll]!=0)flag = 1;
	for(int i=0;i<=lll;i++)flo[i] = '0';
	ans[ant++] = '.';	
	int ll=0, l1=point1-1, l2=point2-1;
	if(flag == 1) integer[0]++;	
	while(l1>=0&&l2>=0){
		integer[ll] += (a[l1]+b[l2]-'0');
		if(integer[ll]>'9'){	integer[ll]-=10;	integer[ll+1]+=1;	}
		ans[ant++]=integer[ll];
		ll++;l1--;l2--;
	}
	while(l1>=0){
		integer[ll] += a[l1];
		if(integer[ll]>'9'){	integer[ll]-=10;	integer[ll+1]+=1;	}
		ans[ant++]=integer[ll];
		ll++;l1--;
	}
	while(l2>=0){
		integer[ll] += b[l2];
		if(integer[ll]>'9'){	integer[ll]-=10;	integer[ll+1]+=1;	}
		ans[ant++]=integer[ll];
		ll++;l2--;
	}
	if(!integer[ll])integer[ll]='\0';
	else{
		ans[ant++] = '1';
		integer[ll] = '1';	
		integer[ll+1]='\0';
	} 
		
	delete integer;
	delete flo;
	int lenl=0, lenr=strlen(ans)-1;
	while((ans[lenl]<='0'||ans[lenl]>'9')&&(ans[lenl]!='.'))lenl++;
	while((ans[lenr]<='0'||ans[lenr]>'9')&&(ans[lenr]!='.'))lenr--;
	int temp = 0;
	while(lenl<=lenr){
		res[temp] = ans[lenr];
		temp++;lenr--;
	}
	res[temp] = '\0';
	delete ans;
	return;
}
int main(){
	int n;
	char *res = new char[300];
	add_float("01.01","9.090",res);
	cout<<res<<endl;
	return 0;
} 
