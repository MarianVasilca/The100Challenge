#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

const char *in_file_name = "divk.in";
const char *out_file_name = "divk.out";

using namespace std;

ifstream in_file;
ofstream out_file;

long long *m;
int *values, *s;
int N, K, a, b;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void read_file()
{

	in_file >> N >> K >> a >> b;

	values = new int[N + 1]();
	s = new int[N + 1]();
	m = new long long[N + 1]();

	for (int i = 1; i <= N; i++)
		in_file >> values[i];

}

void solve()
{
	long long sol = 0;

	for (int i = 1; i <= N; i++)
		s[i] = (s[i - 1] + values[i]) % K;

	for (int i = 1; i <= N; i++) {

		if ((i - a) >= 0)
			m[s[i - a]]++;
		if ((i - b) > 0)
			m[s[i - b -1]]--;

		sol += m[s[i]];
	}

	out_file << sol;

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	solve();

	in_file.close();
	out_file.close();

	delete []values;
	delete []s;
	delete []m;

	return 0;
}
