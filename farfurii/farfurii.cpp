#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

const char *in_file_name = "farfurii.in";
const char *out_file_name = "farfurii.out";

using namespace std;

ifstream in_file;
ofstream out_file;

long long N, K;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void solve()
{
	long long p, x;

	for (p = N; p > 1 && K > (N - p); p--)
		K -= (N - p);

	for (int i = 1; i < p; i++)
		out_file << i << ' ';

	x = p + K;

	out_file << x << ' ';

	for (int i = N; i >= p; i--)
		if (i != x)
			out_file << i << ' ';

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> N >> K;

	solve();

	in_file.close();
	out_file.close();

	return 0;
}
