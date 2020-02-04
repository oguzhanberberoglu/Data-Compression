/*
OGUZHAN BERBEROGLU 24001
CS300 HW2
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashTable.h"
using namespace std;

int main()
{ 
	ifstream readFile;
	ofstream writeFile;
	string fileNameTxt = "compin.txt", outFileTxt = "compout.txt";

	Dictionary<string,int> Dic; // object Dictionary(hash table) created

	readFile.open(fileNameTxt.c_str());
	writeFile.open(outFileTxt.c_str());

	char p,c;
	readFile.get(p); // get the first char before loop
	string p_string(1, p);
	string pc;
	int code = 256; // continue from 256
	while (readFile.get(c))
	{
		string c_string(1, c);
		pc = p_string + c_string; // pc = p + c
		if (!Dic.isKeyExist(pc)) // if pc does not exist; add and display output
		{
			Dic.add(pc, code);
			writeFile << Dic.get(p_string) << " ";
			p_string = c_string;
			code++; // index uptaded
		}
		else
			p_string = pc; // otherwise get the next char
	}
	writeFile << Dic.get(p_string) << " ";

	readFile.close();
	writeFile.close();

	return 0;
}