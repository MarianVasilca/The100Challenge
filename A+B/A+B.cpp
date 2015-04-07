#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "adunare.in";
const char *out_file_name = "adunare.out";

bool is_valid_int(const char *str)
{

	while (*str)
	{
		if(!isdigit(*str))
			return false;
		else
			str++;
	}

	return true;

}

int main()
{
	string line;
	int value = 0;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);

	if (!in_file) {
		cout << "Error opening file for reading" << endl;
		return -1;
	}

	while (getline(in_file, line)) {

		if (is_valid_int(line.c_str()))
			value += atoi(line.c_str());

		else {
			cout << "Error in input file" << endl;
			return -3;
		}
	}

	in_file.close();

	out_file.open(out_file_name, ios::out);

	if (!out_file) {
		cout << "Error opening file for writing" << endl;
		return -2;
	}

	out_file << value;
	out_file.close();

	return 0;
}
