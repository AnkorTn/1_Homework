#include <iostream>
#include <fstream>		
using namespace std;

int main()
{
    ofstream out("file");	//����������������ļ�file����
    ifstream in;			//����һ������������
    fstream io;
    int i;

   //��1��10д�����������
    if (!out) {  cerr << "create file error\n"; return 1;  }	
    for (i = 1; i <= 10; ++i) out.write(reinterpret_cast<char *> (&i), sizeof(int)); 
    out.close();

      in.open("file");						
       if (!in) {  cerr << "open file error\n"; return 1;  }
       in.read(reinterpret_cast<char *> (&i), sizeof(int));
       while (!in.eof()) {
	    cout << i << ' ';					
            in.read(reinterpret_cast<char *> (&i), sizeof(int));
       }
	in.close();
	cout << endl;

     // ��д6Ϊ20
	io.open("file");
	io.seekp(5 * sizeof(int));             // д�ļ���λ��6��λ��
	i = 20;
       io.write(reinterpret_cast<char *> (&i), sizeof(int));  
 // ���¶��ļ�
	io.seekg(0);
      io.read(reinterpret_cast<char *> (&i),  sizeof(int));
	while (!io.eof()) {                
	    cout << i << ' ';					
         io.read(reinterpret_cast<char *> (&i), sizeof(int));
     }
	io.close();

     return 0;
}



