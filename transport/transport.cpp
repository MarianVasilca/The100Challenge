#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

const char *in_file_name = "transport.in";
const char *out_file_name = "transport.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, K;
int maxim = 0;
int *volume;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

bool transport(int middle)
{
	int sum = 0, counter = 0;

	for (int i = 0; i < N; i++) {
		if (sum + volume[i] <= middle)
			sum += volume[i];
		else {
				sum = volume[i];
				counter++;

				if (volume[i] > middle)
					return false;
			}
	}

	if (counter < K)
		return true;
	else
		return false;

}

int solve()
{
	int middle, left = 0, right = maxim;
	bool result;
	middle = (left + right) / 2;

	while (left <= right) {

		middle = (left + right) / 2;
		result = transport(middle);

		if (result) {
			right = middle - 1;
		}
		else
			left = middle + 1;
	}

	return left;

}

void read_file()
{

	in_file >> N >> K;
	volume = new int[N];

	for (int i = 0; i < N; i++) {
		in_file >> volume[i];
		maxim += volume[i];
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

	delete []volume;

	return 0;
}
