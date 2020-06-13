#ifndef Predefined
#define Predefined
	#include<iostream>
	#include<iomanip>
	#include<algorithm>
	using namespace std;
	struct student{	int id;	string name; int chi; int mat; int eng; int tot;}students[1005]; 
	void read(int i);
	void update(int i);
	void modify(int i, int type);
	void print(int i);
	bool cmp1(student a, student b);
	bool cmp2(student a, student b);
	bool cmp3(student a, student b);
#endif
