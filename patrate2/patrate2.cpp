#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

const char *in_file_name = "patrate2.in";
const char *out_file_name = "patrate2.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, *result;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void multiply(int x)
{
	int temp = 0;

	for (int i = 1; i <= result[0]; i++) {
		result[i] = result[i] * x + temp;
		temp = result[i] / 10;
		result[i] = result[i] % 10;
	}

	while (temp) {
		result[0]++;
		result[result[0]] = temp % 10;
		temp /= 10;
	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> N;

	result = new int[N * N];
	result[0] = result[1] = 1;

	for (int i = 2; i <= N; i++)
		multiply(i);

	for (int i = 1; i <= N * N; i++)
		multiply(2);

	for (int i = result[0]; i > 0; i--)
		out_file << result[i];

	in_file.close();
	out_file.close();

	delete []result;

	return 0;
}
