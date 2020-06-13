#include<bits/stdc++.h>
using namespace std;
class Circle{
	private:
		int radius;
		int pointx;
		int pointy;		
	public:
		Circle(int x, int y, int r){
			radius = r;
			pointx = x;
			pointy = y;
		}
		//get0表示获取圆心坐标 
		void getO(int &x, int &y){
			x = pointx;
			y = pointy;
		}
		void move(int x, int y){
			pointx += x;
			pointy += y;
		}
		int getR(){
			return radius;
		}
		void setR(int r){
			radius = r;
		}
		
};
int main(){
    int x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);

    int cx,cy;
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;
    cout<<c.getR()<<endl;

    int move_x,move_y;
    cin>>move_x>>move_y;
    c.move(move_x,move_y);  
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;

    int new_r;
    cin>>new_r;
    c.setR(new_r);
    cout<<c.getR()<<endl;

    return 0;
}
