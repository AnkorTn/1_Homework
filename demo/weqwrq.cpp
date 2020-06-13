#include<bits/stdc++.h>
using namespace std;
class Goods{
	int weight;
	static int total;
	public:
		Goods(int w){
			weight = w;
			total += w;
		}
		~Goods(){
			total-=weight;
		}
		int weightw()const{
			return weight;
		}
		static int totalw(){
			return total;
		}
}; 
void print(Goods obj){
	cout<<obj.weightw()<<endl<<obj.totalw()<<endl;
}
int main(){
	Goods g1(30),g2(50),g3(70);
	print(g1);
	cout<<Goods::totalw()<<endl;
	return 0;
}

