#include<bits/stdc++.h>
using namespace std; 
class orderArray {
	private:
		int storage[100005];
		int l;
		int tot;
    /**
     * @param n: size of orderArray
     */
    public:
    orderArray(int n=0){
    	l = n;
    	tot = 0;
	}
    /**
     * Add a number to the array.
     */
    void add(int x){
    	if(tot==0){
    		storage[tot] = x;
    		tot++;
    		return;
		}
		/*
		if(tot == 1){
			if(storage[0]>x){
				storage[1] = storage[0];
				storage[0] = x;
			}
			else
				storage[1] = x;
			tot++;
			return;
		}*/
    	//storage[tot] = x;
    	//tot ++;
    	int left = 0, mid = (tot-1)/2, right = tot-1;
    	//cout<<"The insert value is:"<<x<<" and tot = "<<tot<<endl;
    	while(left<=right&&left<tot&&right>=0){
    		if(x<=storage[mid])
    			right = mid - 1;
    		else
    			left = mid + 1;
    		mid = (left + right)/2;
    		//cout<<"left="<<left<<"  and right = "<<right<<" and mid = "<<mid<<endl;
		}
		if(storage[mid]<=x)mid++;
		for(int i=tot;i>=mid+1;i--)
			storage[i] = storage[i-1];
		storage[mid] = x;
		tot++;
	}
    /**
     * Return the ith smallest element.
     */
    int findnum(int i){
    	return storage[i];
	}
    /**
     * Print all elements in ascending order.
     */
    void show(){
    	for(int i=0; i<tot-1; i++)
    		cout<<storage[i]<<" ";
		cout<<storage[tot-1]<<endl;
	}
};
int main(){
	orderArray x(20);
	int n,test;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>test;
		x.add(test);
		//x.show();
	}
	x.show();
	cin>>test;
	cout<<x.findnum(test)<<endl;
	cin>>test;
	x.add(test);
	x.show();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>test;
		x.add(test);
	}
	x.show();
	cin>>test;
	cout<<x.findnum(test)<<endl;
	return 0;
}
/*
1 2 3 9 3 5 6 7-1 -2
	-2 -1 1 2 3 3 5 6 7 9
3
	2
1
	-2 -1 1 1 2 3 3 5 6 7 9
20 30 -7 60 -100 9 8 2 2 5
	-100 -7 -2 -1 1 1 2 2 2 3 3 5 5 6 7 8 9 9 20 30 60
7
	2
	


10
1 2 3 9 3 5 6 7 -1 -2
3
1
10
20 30 -7 60 -100 9 8 2 2 5
7
*/
