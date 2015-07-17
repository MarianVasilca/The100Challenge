#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "euclid3.in";
const char *out_file_name = "euclid3.out";

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int get_result(int a, int b, int &x, int &y) {

	if (b == 0) {
		x = 1;
		y = 0;

		return a;

	} else {

		int x0, y0, d;

		d = get_result(b, a % b, x0, y0);

		x = y0;
		y = x0 - (a / b) * y0;
		return d;
	}

}

int main()
{
	int N;
	int a, b, c;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> N;

	for (int i = 0; i < N; i++) {
		in_file >> a >> b >> c;
		
		int d, x, y;

		d = get_result(a, b, x, y);

		if (c % d)
			out_file << "0 0" << endl;
		else
			out_file << x * (c / d) << " " << y * (c / d) << endl;
	}	

	in_file.close();
	out_file.close();

	return 0;

}