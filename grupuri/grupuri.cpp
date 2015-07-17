#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

const char *in_file_name = "grupuri.in";
const char *out_file_name = "grupuri.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, K;
long long maxim = 0;
int *values;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

bool is_valid(long long middle)
{
	long long sum = 0;

	for (int i = 0; i < N; i++)
		if (values[i] < middle)
			sum += values[i];
		else
			sum	+= middle;

	if (K * middle <= sum)
		return true;
	else
		return false;

}

long long solve()
{
	long long left = 1, right = maxim / K, result = 0, middle;

	while (left <= right) {

		middle = (left + right) / 2;

		if (is_valid(middle)) {
			result = middle;
			left = middle + 1;
		} else
			right = middle - 1;
	}

	return result;
}

void read_file()
{

	in_file >> K >> N;
	values = new int[N];

	for (int i = 0; i < N; i++) {
		in_file >> values[i];
		maxim += values[i];
	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	out_file << solve();

	in_file.close();
	out_file.close();

	delete []values;

	return 0;
}
