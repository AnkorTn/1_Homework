#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("article.txt");
	ofstream fout("statistics.txt");
	int n_para = 0;
	int n_word = 0;
	int n_char = 0;
	while (!fin.fail())	{
		static char line[31451];
		fin.getline(line, 31450);
		int len = strlen(line), i = 0, exist = 0;
		while (i < len)		{
			if (line[i] != '.' && line[i] != ',' && line[i] != ' ' && line[i] != '\n')			{
				++n_word;
				exist++;
				while (i < len && line[i] != '.' && line[i] != ',' && line[i] != ' ' && line[i] != '\n')				{
					++n_char;
					i++;
				}
			}
			else			{
				++i;
			}
		}
		if (exist)		{
			++n_para;
		}
	}
	fout << n_para << endl
		 << n_word << endl
		 << n_char;
	fin.close();
	fout.close();
	return 0;
}
