#include<bits/stdc++.h>
using namespace std;
struct student{	int id;	string name; int chi; int mat; int eng; int tot;}students[1005]; 
void update(int i);
void modify(int i, int type);
void print(int i);
bool cmp1(student a, student b);
bool cmp2(student a, student b);
bool cmp3(student a, student b);
int main(){
	//op 操作 tot 学生数 flag 错误判断标志 
	int n, op,tot=0, flag;
	cin>>n;
	while(n--){
		cin>>op;
		flag = 0;
		switch(op){
			//数据读入，关键：判断重复 
			case 1:{
				//为了保证不会出问题的读入方式 
				int tid, tchi, tmat, teng; string tname;
				cin>>tid>>tname>>tchi>>tmat>>teng;
				for(int i=0;i<tot;i++)//异常检测 
					if(students[i].id==tid){
						cout<<"Duplicate detected."<<endl;
						flag = 1;
					}
				//赋值
				if(!flag){
					students[tot].id  = tid;
					students[tot].name= tname;
					students[tot].chi = tchi;
					students[tot].mat = tmat;
					students[tot].eng = teng;
					students[tot].tot = tchi + tmat + teng;
					tot++;
				}
				break;
			}
			case 2:{
				string s; int ope, tid, type = 0;
				cin>>tid>>s; ope = s[0];
				//记录这个操作的第几种，然后进行转移到另一个函数操作去 
				switch(ope){
					case 73:{type = 1;	break;	}//ID改变 
					case 78:{type = 2;	break;	}//name改变 
					case 67:{type = 3;	break;	}//chi改变 
					case 77:{type = 4;	break;	}//mat改变 
					default:{type = 5;	break;	}//eng改变 
				}
				for(int i=0;i<tot;i++){
					if(students[i].id == tid){
						flag = 1;
						modify(i,type);
					}
				}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			}
			case 3:{
				int tid; cin>>tid;
				for(int i=0;i<tot;i++)
					if(students[i].id == tid){
						flag = 1;
						print(i);
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			}
			case 4:{
				string tname; cin>>tname;
				sort(students,students+tot,cmp1);
				for(int i=0;i<tot;i++)
					if(students[i].name == tname){
						flag = 1;
						print(i);
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			}
			case 5:{
				sort(students,students+tot,cmp2);
				for(int i=0;i<tot;i++)
					print(i);
				break;
			}
			default:{//case 6
				sort(students,students+tot,cmp3);
				for(int i=0;i<tot;i++)
					print(i);
				break;
			}
		}
	}
	return 0;
}
void update(int i){
	students[i].tot = students[i].chi + students[i].mat + students[i].eng;
}
void modify(int i, int type){
	switch(type){
		case 1:{ int tid;	cin>>tid;	students[i].id = tid;					break;	}
		case 2:{ string tname;cin>>tname;students[i].name =tname;				break;	}
		case 3:{ int tchi;	cin>>tchi;	students[i].chi=tchi;	update(i);		break;	}
		case 4:{ int tmat;	cin>>tmat;	students[i].mat=tmat;	update(i);		break;	}
		default:{int teng;	cin>>teng;	students[i].eng=teng;	update(i);		break;	}
	}
	return;
}
void print(int i){
	cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].mat<<setw(4)<<students[i].eng<<endl;
	return;
}
bool cmp1(student a, student b){
	if(a.name == b.name)	return a.id<b.id;
	return a.name<b.name;
}
bool cmp2(student a, student b){
	return a.id<b.id;
}
bool cmp3(student a, student b){
	if(a.tot==b.tot) return a.id<b.id;
	return a.tot>b.tot;
}
