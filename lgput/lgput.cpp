#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const char *in_file_name = "lgput.in";
const char *out_file_name = "lgput.out";
const int d = 1999999973;
long long N, P;

using namespace std;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

long long get_value()
{
	long long result = 1;

	/* parcurgem toti bitii lui P */
	for (int i = 0; (1<<i) <= P; ++ i) {

		/* Daca bitul curent al lui P este 1 */
		if (((1<<i) & P) > 0) {
            result = (result * N) % d;
     	}

            N = (N * N) % d; 
	}

	return result;

}

int main()
{

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> N;
	in_file >> P;

	out_file << get_value();

	in_file.close();
	out_file.close();

	return 0;
}