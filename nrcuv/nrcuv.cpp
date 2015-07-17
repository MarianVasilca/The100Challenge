#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

const char *in_file_name = "nrcuv.in";
const char *out_file_name = "nrcuv.out";
const int PMAX = 26;
const int NMAX = 1001;
const int MOD = 104659;

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M, **DP;
bool **pairs;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}


void write()
{

    int result = 0;

        for (int j = 0; j < PMAX; j++) {
            result = (result + DP[N][j]) % MOD;
        }

    out_file << result;
}

int char_to_int(char c)
{
	return ((int)c - (int)'a');
}

void clean()
{
	for (int i = 0; i < NMAX; i++)
		delete[] DP[i];
	delete []DP;

	for (int i = 0; i < PMAX; i++)
		delete[] pairs[i];
	delete []pairs;
}

void read_file()
{
	char x, y;

	pairs = new bool*[PMAX];
	for (int i = 0; i < PMAX; i++)
		pairs[i] = new bool[PMAX]();

	in_file >> N >> M;

	DP = new int*[NMAX + 1];

	for (int i = 0; i < NMAX; i++)
		DP[i] = new int[NMAX]();

	for (int i = 1; i <= M; i++) {
		in_file >> x >> y;
		pairs[char_to_int(x)][char_to_int(y)] = true;
		pairs[char_to_int(y)][char_to_int(x)] = true;
	}

	for (int i = 0; i < PMAX; i++)
		DP[1][i] = 1;

}

void solve()
{
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < PMAX; j++) {
			for (int k = 0; k < PMAX; k++) {
				if (pairs[k][j] == false)
					DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;
			}
		}
	}
}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	solve();

	write();

	in_file.close();
	out_file.close();

	clean();

	return 0;
}
