#include<bits/stdc++.h>
using namespace std;
class SavingAccount {
	private:
		static int tot;
		float new_rate; 
		float money;
		int id;
	public:
		SavingAccount(int mon){
			new_rate = 0.05;
			money = 1.0*mon;
			id = tot;
			tot++;
		}
		void calculate(){
			money = money * (1+new_rate);
		} 
		void display(){
			cout<<setiosflags(ios::fixed)<<setprecision(2);
			cout<<id<<" "<<money<<" "<<new_rate<<endl;
		} 
		void changerate(float rate){
			new_rate = rate;
		}
};
int SavingAccount::tot = 1; 
int main(){
    // 1st month
    int first_money, second_money;
    cin>>first_money>>second_money;
    SavingAccount first(first_money);
    SavingAccount second(second_money);
    first.display();
    second.display();

    // 2nd month
    float new_rate;
    cin>>new_rate;
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    first.changerate(new_rate);
    second.changerate(new_rate);

    // 3rd month
    int third_money;
    cin>>third_money;
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    SavingAccount * p = new SavingAccount(third_money);

    // 4th month
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    p->calculate();
    p->display();

    delete p;
    return 0;
}
