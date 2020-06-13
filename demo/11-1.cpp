#include<bits/stdc++.h>
using namespace std;
int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
class Date {
	friend ostream& operator<<(ostream &os, const Date& obj);
	private:
		int year;
		int month;
		int day;
		bool leap_year;
	public:
		
    /**
     * Defaults to 1900-01-01
     */
    //If a year is a leap_year, leap_year=0; else leap_year = 1;
    	Date(){	year = 1900;	month = 1;	day = 1;	leap_year = 0;	}
    /**
     * Init with year-month-day.
     *
     * Print "Invalid date." when y-m-d is an invalid date. Set to
     * 1900-01-01.
     */
    	Date(int m, int d, int y){
    		bool l_y = !(y%400==0||(y%4==0&&y%100!=0));
    		if(m<1||m>12||d<0||d>days[m]||(m==2&&d>days[m]-l_y)){
    			cout<<"Invalid date."<<endl;
    			year = 1900;	month = 1;	day = 1;	leap_year = 0;
			}
			else{
				year = y; month = m; day = d;
				leap_year = l_y;
			}
		}
    /**
     * If y-m-d is invalid, don't change the date and print "Invalid date.".
     */
    	void setDate(int m, int d, int y){
	    	bool l_y = !(y%400==0||(y%4==0&&y%100!=0));
	    	if(m<1||m>12||d<0||d>days[m]||(m==2&&d>days[m]-l_y))
	    		cout<<"Invalid date."<<endl;
	    	else{	year = y; month = m; day = d;	leap_year = l_y;}
		}
    // Overload
    //  ++ (prefix and postfix) for increment 1 day
    //prefix ::Counter & operator++(); 
    //postfix::Counter operator++(int); 
    Date &operator++(){
	    ++day;
	    if(month==2&&day>days[month]-leap_year){
	    	month = 3;
	    	day = 1;
		}
		else{
			if(day>days[month]){
				day = 1;
				month++;
				if(month>12){
					month = 1;
					year ++;
					leap_year = !(year%400==0||(year%4==0&&year%100!=0));
				}
			}
		}
		return *this;
	}
    Date operator++(int){
    	Date tmp = *this;
    	++day;
	    if(month==2&&day>days[month]-leap_year){
	    	month = 3;
	    	day = 1;
		}
		else{
			if(day>days[month]){
				day = 1;
				month++;
				if(month>12){
					month = 1;
					year ++;
					leap_year = !(year%400==0||(year%4==0&&year%100!=0));
				}
			}
		}
		return tmp;
    }
    
    //  += for adding positive amount of days.
    
    Date operator+=(int x){
    	//Date tmp = *this;
    	while(x>0){
    		++*this;
    		x--;
		}
		return *this;
    }
    
    //  < for comparsion between dates
    bool operator<(const Date &d1){
    	if(year!=d1.year) 	return year<d1.year;
    	if(month!=d1.month)	return month<d1.month;
    	return day<d1.day;
	}
    
    ~Date(){}
};
//  << for output with cout, format: 1900-01-01, no new line
ostream& operator<<(ostream &os, const Date& obj){
	os<<obj.year<<"-";	if(obj.month<10)	os<<"0";
	os<<obj.month<<"-";	if(obj.day<10)		os<<"0";
	os<<obj.day;
	return os;
}
int main(){
	int a,b,c;
	Date x;
	cout<<"x="<<x<<endl;
	cin>>a>>b>>c;
	Date y(a,b,c);
	cout<<"y="<<y<<endl;
	y++;
	cout<<"y++:y="<<y<<endl;
	++y;
	cout<<"++y:y="<<y<<endl;
	y+=5;
	cout<<"y+=5;y="<<y<<endl;
	cin>>a>>b>>c;
	y.setDate(a,b,c);
	cout<<"y="<<y<<endl;
	y++;
	cout<<"y++;y="<<y<<endl;
	++y;
	cout<<"++y;y="<<y<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	cout<<"y++="<<y++<<endl;
	cout<<"++y="<<++y<<endl;
	cout<<"whether y<x?"<<(y<x)<<endl;
	cout<<"Now input the day n to satisfy that y+=n";
	cout<<"------------"<<endl;
	int t;
	cin>>t;
	cout<<"y="<<y<<endl;
	y += t;
	cout<<"y+=t;y="<<y<<endl;
	return 0;
} 
