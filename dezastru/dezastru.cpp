#include <iostream>
#include <fstream>
#include <stdlib.h>


const char *in_file_name = "dezastru.in";
const char *out_file_name = "dezastru.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, K;
double *probability, **comb, **d;

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

	for (int i = 1; i <= N; i++) {

		d[i - 1][0] = 1;
		comb[i - 1][0] = 1;

		for (int j = 1; j <= K; j++) {
			d[i][j] = d[i - 1][j - 1] * probability[i] + d[i - 1][j];
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}

	}

	out_file.precision(6);
	out_file << fixed << d[N][K] / comb[N][K];

}

void read_file()
{

	in_file >> N >> K;

	probability = new double[N + 1]();
	comb = new double*[N + 1];
	d = new double*[N + 1];

	for (int i = 0; i <= N; i++) {
		comb[i] = new double[N + 1]();
		d[i] = new double[N + 1]();
	}

	for (int i = 1; i <= N; i++)
		in_file >> probability[i];

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

    for (int i = 0; i <= N; i++) {
    	delete [] comb[i];
    	delete [] d[i];
    }

    delete []comb;
    delete []d;
    delete []probability;

    return 0;
}
