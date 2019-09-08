#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
	int wordcount = 0;
	string textnum;
	string textnum2;
	string textnum3;
	char ctext;
	int i = 0;
	vector<string> content;
	vector<string> content2;
	ifstream infile;
	ifstream infile2;
	int numbertotal = 0;
	cout << "파일 읽기" << endl;
	infile.open("third.txt");
	infile2.open("third.txt");
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, textnum);
			if (textnum.size() >= 1) {
				content.push_back(textnum);
				if (textnum[0] != ' ') wordcount++;
				for (int i = 0; i < textnum.length(); i++)
				{
					if (textnum[i] == ' ')
					{
						if (textnum[i + 1] == ' ')
							wordcount++;
						else if (textnum[i + 1])
							wordcount++;
					}


				}

				
			}
		}
	}
	infile.close();

	for (int i = 0; i < content.size(); i++) 
	{
		cout << content[i] << endl;
	}
	


	cout << endl;

	cout << "word count : "<< wordcount << endl;
	cout << "number :";
	if (infile2.is_open()) {
		while (!infile2.eof()) {
			getline(infile2, textnum2);
			if (textnum2.size() >= 1 && !isalpha(textnum2[0]))
			{
						content2.push_back(textnum2);
						i = stoi(textnum2);
						
					}
				
			
		}


	}
	infile2.close();
	
	
	for (int i = 0; i < content2.size(); i++)
	{
		textnum3 += content2[i];

	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		textnum3.erase(i, isalpha(textnum3[i]));
	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		textnum3.erase(i, isalpha(textnum3[i]));
	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		textnum3.erase(i, isalpha(textnum3[i]));
	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		if (textnum3[i] == '1' && textnum3[i + 1] == '0')
		{
			ctext = textnum3[i + 2];
			textnum3[i + 2] = ' ';
			textnum3[i + 3] = ctext;

		}
	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		if (textnum3[i] == '-' && textnum3[i + 1] == '2')
		{
			ctext = textnum3[i + 2];
			char ctext2 = textnum3[i + 3];
			textnum3[i + 2] = ' ';
			textnum3[i + 3] = ctext;
			textnum3[i + 4] = ctext2;

		}
	}
	for (int i = 0; i < textnum3.size(); i++)
	{
		if (textnum3[i] == ' ')
			numbertotal++;
	}numbertotal++;
	cout << textnum3 << endl;
	cout << "numbertotal :" << numbertotal << endl;
}