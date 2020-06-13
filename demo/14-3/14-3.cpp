#include<bits/stdc++.h>
using namespace std;
class client{
	
	public:
		char name[20];
		long long _id;
		char id[12];
		char birth[7];
		char phone[12];
		void cid(){
			_id = 0;
			for(int i=0;i<strlen(id);i++){
				_id*=10;
				_id+=id[i]-'0';
			}
		}
		client &operator =(const client &a1){
			if(this == &a1) return *this;
			_id = a1._id+1;
			long long tmp=10000000000, rat = _id;
			while(tmp>rat)	tmp/=10;	int j=0;
			while(tmp>0){
				id[j] = rat/tmp + '0';
				rat %=tmp;
				tmp /= 10;
				j++;
			}
			j++; for(;j<=11;j++)	id[j] = '\0';
			//id[i] =  a1.id[i];
			for(int i=0;i<=11;i++){	phone[i]=a1.phone[i];	}
			for(int i=0;i<=19;i++){	name[i] =a1.name[i];	}
			for(int i=0;i<=6 ;i++){	birth[i]=a1.birth[i]; 	} 
			return *this;
		}
};
int main(){
	client data[1005];
	int numb = 0, i;
	long long max_id = 0;
	//ofstream outf("output.txt",ios::binary);
	ifstream inf("output.txt",ios::binary);
	while(!inf.eof()){
		inf.read(reinterpret_cast<char *> (&data[numb].id), 12*sizeof(char));
		data[numb].cid();
		max_id = (max_id>data[numb]._id)?max_id:data[numb]._id;
		inf.read(reinterpret_cast<char *> (&data[numb].name), 20*sizeof(char));
		inf.read(reinterpret_cast<char *> (&data[numb].birth), 7*sizeof(char));
		inf.read(reinterpret_cast<char *> (&data[numb].phone), 12*sizeof(char));
		numb++;
	}
	inf.close();
	numb--;
	int op;
	ofstream outf("output.txt",ios::binary);
	outf.write(reinterpret_cast<char *> (&data[0].id[i]),    12*sizeof(char));
	outf.write(reinterpret_cast<char *> (&data[0].name[i]),  20*sizeof(char));
	outf.write(reinterpret_cast<char *> (&data[0].birth[i]), 7*sizeof(char));
	outf.write(reinterpret_cast<char *> (&data[0].phone[i]), 12*sizeof(char));
	while(!cin.eof()){
		char s[30];
		cin>>op;
		switch(op){
			case 1:
				{
					cin>>s;
					for(i=0;i<numb;i++)
						if(strcmp(s,data[i].id)==0)
							break;
					data[numb] = data[i];	max_id = (max_id>data[numb]._id)?max_id:data[numb]._id;
					outf.write(reinterpret_cast<char *> (&data[numb].id),    12*sizeof(char));
					outf.write(reinterpret_cast<char *> (&data[numb].name),  20*sizeof(char));
					outf.write(reinterpret_cast<char *> (&data[numb].birth), 7*sizeof(char));
					outf.write(reinterpret_cast<char *> (&data[numb].phone), 12*sizeof(char));
					numb++;
				}
				break;
			/*case 2:
				cin>>s;
				if(s=="phone")	phone();	else birth();	break;
			case 3:
				char a[30], b[30];
				cin>>s>>a>>b;
				add(s,a,b);
				break;*/
			default:
				/*
				
					{
		ifstream t("output.txt",ios::binary);
	numb = 0;
	while(!inf.eof()){
		t.read(reinterpret_cast<char *> (&data[numb].id), 12*sizeof(char));
		data[numb].cid();
		max_id = (max_id>data[numb]._id)?max_id:data[numb]._id;
		t.read(reinterpret_cast<char *> (&data[numb].name), 20*sizeof(char));
		t.read(reinterpret_cast<char *> (&data[numb].birth), 7*sizeof(char));
		t.read(reinterpret_cast<char *> (&data[numb].phone), 12*sizeof(char));
		numb++;
	}
	t.close();
	for(int i=0;i<numb-1;i++)
		cout<<data[i].id<<" _id= "<<data[numb]._id<<"   "<<data[numb].name<<"  "<<data[numb].birth<<"   "<<data[numb].phone<<endl;
	}
				
				*/
				
				
				
				outf.close();
				return 0;
		}
	}
	outf.close();
	
	

	
	
	
	
	return 0;
}
/*
void getdata(){
	ifstream inf("output.txt",ios::binary);
	ofstream outf("out.txt",ios::binary);
	//get the id number
	{
		char s[100];
    	inf.seekg(0);
    	inf>>s;
		cout<<"s:="<<s<<endl;
		int i=0; int l=strlen(s);
		while(i<12){
			outf.write(reinterpret_cast<char *> (&s[i]), sizeof(char)); 
			//outf.write((char*)&s, sizeof(s));
			i++;
		}
		//outf.write((char*)&s, sizeof(s));
		inf.clear();//清除流状态标志
	}
	
	//get the name
	{
		char s[100];
    	inf.seekg(12);
    	inf>>s;
		cout<<"s:="<<s<<endl;
		int i=0; int l=strlen(s);
		while(i<20){
			outf.write(reinterpret_cast<char *> (&s[i]), sizeof(char)); 
			//outf.write((char*)&s, sizeof(s));
			i++;
		}
		//outf.write((char*)&s, sizeof(s));
		inf.clear();//清除流状态标志
	}
	
	//get the born date
	{
		char s[100];
    	inf.seekg(32);
    	inf>>s;
		cout<<"s:="<<s<<endl;
		int i=0; int l=strlen(s);
		while(i<7){
			outf.write(reinterpret_cast<char *> (&s[i]), sizeof(char)); 
			//outf.write((char*)&s, sizeof(s));
			i++;
		}
		//outf.write((char*)&s, sizeof(s));
		inf.clear();//清除流状态标志
	}
	
	
	//get the phone number
	{
		char s[100];
    	inf.seekg(39);
    	inf>>s;
		cout<<"s:="<<s<<endl;
		int i=0; int l=strlen(s);
		while(i<12){
			outf.write(reinterpret_cast<char *> (&s[i]), sizeof(char)); 
			//outf.write((char*)&s, sizeof(s));
			i++;
		}
		//outf.write((char*)&s, sizeof(s));
		inf.clear();//清除流状态标志
	}
	inf.close();
	outf.close();
}*/
