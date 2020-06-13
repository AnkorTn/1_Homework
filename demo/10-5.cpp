#include<bits/stdc++.h>
using namespace std; 
// Define and implement class Josephus
// Never write main() here
class Josephus {
	private:
		int *storage;
		int l;
		int step;
	public:
		Josephus(int n, int m){
			l = n;
			step = m;
			storage = new int[n+1];
			for(int i=0;i<=n;i++)
				storage[i] = 1;
		}
		void simulate(){
			int fla = 2, tot = 0, n = l;
			while(n > 0){
				if(storage[fla])
					tot++;
				if(tot == step){
					storage[fla] = 0;
					cout<<fla<<endl;
					tot = 0;
					n--;
				}
				fla++;
				if(fla>l)
					fla = 1;
			}
		}
		~Josephus(){
			delete []storage;
		}
};
int main(){
	int n, m;
	cin >> n >> m;
	Josephus obj(n, m);
	obj.simulate();
	return 0;
}
