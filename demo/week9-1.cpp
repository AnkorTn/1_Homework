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
//cmp1��ѧ������ 
bool cmp1(student a, student b){
	return a.id<b.id;	
} 
//cmp2���ֽܷ���,ѧ������ 
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
				//���ѧ����Ϣ��������Ϊ�ÿո������ѧ�š����֡����ġ���ѧ��Ӣ��ɼ���
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
				//�޸�ѧ����Ϣ��������ΪID/N/C/M/E����ʾҪ�޸ĵ�����һ�����Ǹ������ֵ��
				cin>>query>>ct;
				//�ж�ѧ���Ƿ���� 
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
				//��ѧ�Ų�ѯѧ����Ϣ����ͬһ���ڸ���ѧ�š���ѧ�Ų�һ���ж�Ӧ��ѧ����
				cin>>query;
				//�ж�ѧ���Ƿ���� 
				for(int i=0;i<tot;i++)
					if(students[i].id==query){
						flag = 1;
						cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			case 4:
				//��������ѯѧ����Ϣ����ͬһ���ڸ����������и�������ѧ����һ�����ڣ�
				cin>>name;
				flag = 0;
				//�ж�ѧ���Ƿ���� 
				sort(students,students+tot,cmp1);
				for(int i=0;i<tot;i++)
					if(strcmp(students[i].name,name)==0){
						flag = 1;
						//���ѧ��
						//��������Ҫ����ģ�����
						//��û���򣡣��� 
						cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
					}
				if(!flag)
					cout<<"Not found."<<endl;
				break;
			case 5:
				//��ѧ��������������������ݣ�
				sort(students,students+tot,cmp1);
				//���ѧ�� 
				for(int i=0;i<tot;i++)
					 cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
				break;
			case 6:
				//���ֽܷ�����������������ݡ�
				sort(students,students+tot,cmp2);
				//���ѧ�� 
				for(int i=0;i<tot;i++)
					 cout<<setw(4)<<students[i].id<<setw(16)<<students[i].name<<setw(4)<<students[i].chi<<setw(4)<<students[i].math<<setw(4)<<students[i].eng<<endl;
				break;
			default:
				break;
		}
	}
	return 0;
} 
