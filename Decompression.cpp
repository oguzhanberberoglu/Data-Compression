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
	string fileNameTxt = "compout.txt", outFileTxt = "decompout.txt";

	Dictionary<int, string> Dic; // object Dictionary(hash table) created

	readFile.open(fileNameTxt.c_str());
	writeFile.open(outFileTxt.c_str());

	
	
	int code = 256; // continue from 256
	int prv, x; // previous and current codes
	string out = "", text = "";
	char fc; // to get first character
	readFile >> x; // first char read
	prv = x;

	while (readFile >> x){
		text = Dic.get(prv);
		if (!Dic.isValueExist(x)) // if it is not exist in Dictionary; take the first character of previous
			fc = Dic.get(prv).at(0);
		else// if it is exist get the value of it
			fc = Dic.get(x).at(0);
		out = text + fc; // merged the first character and the previous' value; will be the next index in the dictionary
		Dic.add(out,code); // new item added; or stay same if it exist
		code++; // index uptaded
		prv = x;
	}

	readFile.clear();
	readFile.seekg(0);
	int output;
	while (readFile >> output) // output
		writeFile << Dic.get(output);
	readFile.close();
	writeFile.close();

	return 0;
}