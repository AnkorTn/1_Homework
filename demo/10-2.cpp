#include<bits/stdc++.h>
using namespace std;
class Time {
	private:
		int hour;
		int minute;
		int second;
	public:
		Time(int h=0, int min=0, int s=0){
			hour = h;
			minute = min;
			second = s;
		}
		void add(int s){
			second += s;
			minute += second/60;
			second %= 60;
			hour   += minute/60;
			minute %= 60;
			hour   %= 24;
		}
		void settime(int h, int min, int s){
			hour = h;
			minute = min;
			second = s;
		}
		void display(){
			if(hour<10) 	cout<<"0";	cout<<hour<<":";
			if(minute<10)	cout<<"0";	cout<<minute<<":";
			if(second<10)	cout<<"0";	cout<<second<<endl;
		}
};
int main(){
    int h1, m1, s1,h2, m2, s2, addseconds1, addseconds2;
    cin >> h1 >>m1 >>s1;
    cin >> addseconds1;
    cin >> h2 >>m2 >>s2;
    cin >> addseconds2;
    Time t(h1,m1,s1);
    t.display();
    t.add(addseconds1);
    t.display();
    t.settime(h2,m2,s2);
    t.display();
    t.add(addseconds2);
    t.display();
    return 0;
}
