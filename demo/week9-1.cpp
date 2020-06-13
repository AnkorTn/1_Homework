#include<bits/stdc++.h>
using namespace std;
struct student{
	int id;
	char name[14];
	int chi;
	int math;
	int eng;
	int tot;
}students[1024];
//cmp1按学号升序 
bool cmp1(student a, student b){
	return a.id<b.id;	
} 
//cmp2按总分降序,学号升序 
bool cmp2(student a, student b){
	if(a.tot==b.tot) return a.id<b.id; 
	return a.tot>b.tot;
}
int main(){
	int n,op,tot=0;
	int query; char ct[3];
	int tmp,opt; char temp[14];
	bool flag = 0;	int id,chi,math,eng;	char name[14];
	cin>>n;
	while(n--){
		cin>>op;
		flag = 0;
		switch(op){
			case 1:
				//添加学生信息，接下来为用空格隔开的学号、名字、语文、数学、英语成绩；
				cin>>id>>name>>chi>>math>>eng;
				for(int i=0;i<tot;i++)
					if(students[i].id==id){
						flag = 1;
						break;
					}
				if(!flag){
					students[tot].id = id;
					for(int i=0;i<strlen(name);i++)
						students[tot].name[i] = name[i];
					students[tot].name[strlen(name)] = '\0';
					students[tot].chi = chi;
					students[tot].math=math;
					students[tot].eng = eng;
					students[tot].tot = students[tot].chi+students[tot].math+students[tot].eng;
					tot++;
				}
				else
					cout<<"Duplicate detected."<<endl;
				break;
			case 2:
				//修改学生信息，接下来为ID/N/C/M/E，表示要修改的是哪一项，最后是该项的新值；
				cin>>query>>ct;
				//判断学生是否存在 
				for(int i=0;i<tot;i++)
					if(students[i].id==query){
						flag = 1;
						break;
					}
				opt = ct[0];
				if(flag){
					switch(opt){
						case 73://ID 
							cin>>tmp;
							for(int i=0;i<tot;i++)
								if(students[i].id==query){
									students[i].id=tmp;
									break;
								}		
							break;
						case 78://NAME
							cin>>temp;
							for(int i=0;i<tot;i++)
								if(students[i].id==query){
									for(int j=0;j<strlen(temp);j++)
										students[i].name[j]=temp[j];
									students[i].name[strlen(temp)]='\0';
									break;
								}
							break;
						case 67://CHI
							cin>>tmp;
							for(int i=0;i<tot;i++)
								if(students[i].id==query){
									students[i].chi=tmp;
									break;
								}	
							break;
						case 77://MATH
							cin>>tmp;
							for(int i=0;i<tot;i++)
								if(students[i].id==query){
									students[i].math=tmp;
									break;
								}
							break;
						default://ENGLISH
							cin>>tmp;
							for(int i=0;i<tot;i++)
								if(students[i].id==query){
									students[i].eng=tmp;
									break;
								}
							break;
					}
				}
				else
					cout<<"Not found."<<endl;
				break;
			case 3:
				//按学号查询学生信息，在同一行内给出学号。该学号不一定有对应的学生；
				cin>>query;
				//判断学生是否存在 
				for(int i=0;i<tot;i++)
					if(students[i].id==query){
						flag = 1;
						cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			case 4:
				//按姓名查询学生信息，在同一行内给出姓名。有该姓名的学生不一定存在；
				cin>>name;
				flag = 0;
				//判断学生是否存在 
				sort(students,students+tot,cmp1);
				for(int i=0;i<tot;i++)
					if(strcmp(students[i].name,name)==0){
						flag = 1;
						//输出学生
						//这里是需要排序的！！！
						//还没排序！！！ 
						cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			case 5:
				//按学号升序排序并输出所有数据；
				sort(students,students+tot,cmp1);
				//输出学生 
				for(int i=0;i<tot;i++)
					 cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
				break;
			case 6:
				//按总分降序排序并输出所有数据。
				sort(students,students+tot,cmp2);
				//输出学生 
				for(int i=0;i<tot;i++)
					 cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
				break;
			default:
				break;
		}
	}
	return 0;
} 
