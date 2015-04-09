#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file_handler.h"
using namespace std;
    
#define GetCurrentDir _getcwd

FileHandler::FileHandler(string in_filename)
{
	char in_filepath[FILENAME_MAX];
	char out_filepath[FILENAME_MAX];
	char cCurrentPath[FILENAME_MAX];

	string out_filename = "out.txt";

	_chdir("..\\");
	GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));
	sprintf_s(in_filepath, sizeof(in_filepath), "%s\\tests\\%s", cCurrentPath, in_filename.c_str());
	sprintf_s(out_filepath, sizeof(out_filepath), "%s\\tests\\%s", cCurrentPath, out_filename.c_str());

	infile.open(in_filepath);
	outfile.open(out_filepath);
	if (infile.is_open())
	{
		cout << "   INFO: File (" << in_filename << ") opened successfully" << endl;
	}
	else
	{
		cout << "   ERROR: File (" << in_filepath << ") could NOT be opened" << endl;
	}
	if (outfile.is_open())
	{
		cout << "   INFO: File (" << out_filename << ") opened successfully" << endl;
	}
	else
	{
		cout << "   ERROR: File (" << out_filepath << ") could NOT be opened" << endl;
	}
	cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(infile.rdbuf()); //redirect std::cin to in.txt!

	coutbuf = cout.rdbuf(); //save old buf
	//cout.rdbuf(outfile.rdbuf()); //redirect std::cin to out.txt!
}

FileHandler::~FileHandler()
{
	infile.close();
	outfile.close();
	cin.rdbuf(cinbuf);   //reset to standard input again
	cout.rdbuf(coutbuf);
}