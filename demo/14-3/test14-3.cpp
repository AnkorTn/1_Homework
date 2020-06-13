#include <iostream>
#include <fstream>		
using namespace std;

int main()
{
    ofstream out("file");	//定义输出流，并与文件file关联
    ifstream in;			//定义一个输入流对象
    fstream io;
    int i;

   //将1～10写到输出流对象
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

     // 改写6为20
	io.open("file");
	io.seekp(5 * sizeof(int));             // 写文件定位到6的位置
	i = 20;
       io.write(reinterpret_cast<char *> (&i), sizeof(int));  
 // 重新读文件
	io.seekg(0);
      io.read(reinterpret_cast<char *> (&i),  sizeof(int));
	while (!io.eof()) {                
	    cout << i << ' ';					
         io.read(reinterpret_cast<char *> (&i), sizeof(int));
     }
	io.close();

     return 0;
}



