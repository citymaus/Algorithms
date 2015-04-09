// Redirects cin to file input
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler
{
	string dir;
	ifstream infile;
	ofstream outfile;
	streambuf* cinbuf;
	streambuf* coutbuf;

public:
	FileHandler(string in_filename);
	~FileHandler();
//	string getcwd();
};