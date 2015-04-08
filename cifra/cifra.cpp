#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "cifra.in";
const char *out_file_name = "cifra.out";

int *double_digits = new int[100];

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int get_power(int n)
{
	int digit = 1;

	for (int i = 1; i <= n; i++)
		digit *= n, digit %= 10;

	return digit;
}

void set_double_vector()
{
	double_digits[0] = 0;
	for (int i = 1; i < 100; i++)
		double_digits[i] = (double_digits[i - 1] + get_power(i)) % 10;

}

int main()
{

	string line;
	string characters;
	char *results;
	int N, x, length = 0;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	getline(in_file, line);
	N = atoi(line.c_str());

	results = new char[N*2+10];

	set_double_vector();

	for (int i = 0; i < N; i++) {

		getline(in_file, line);

		length = line.length();

		if (length == 1) {
			x = line[length - 1] - '0';
		}
		else {
			x = ((line[length - 2] - '0') * 10) + (line[length - 1] - '0');
		}

		sprintf(results+2*i, "%d\n", double_digits[x]);

	}

	out_file << results;

	in_file.close();
	out_file.close();

	delete []results;
	delete []double_digits;

	return 0;
}
