#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "cmmdc.in";
const char *out_file_name = "cmmdc.out";


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

int cmmdc(int a, int b)
{

	if (b == 0)
		return a == 1 ? 0 : a;
	else
		return cmmdc(b, a % b);
}

int main()
{
	string line;
	int a, b, cmmdc_value;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	out_file.open(out_file_name, ios::out);

	if (!in_file) {
		cout << "Error opening file for reading" << endl;
		return -1;
	}

	if (!out_file) {
		cout << "Error opening file for writing" << endl;
		return -2;
	}

	if (!getline(in_file, line)) {
		cout << "Error reading line" << endl;
		return -3;
	}

	if (is_valid_int(line.c_str()))
			a = atoi(line.c_str());
	else {
		cout << "Error in input file" << endl;
		return -4;
	}

	if (!getline(in_file, line)) {
		cout << "Error reading line" << endl;
		return -3;
	}

	if (is_valid_int(line.c_str()))
			b = atoi(line.c_str());
	else {
		cout << "Error in input file" << endl;
		return -4;
	}

	cmmdc_value = cmmdc(a, b);
	out_file << cmmdc_value;

	in_file.close();
	out_file.close();

	return 0;
}
