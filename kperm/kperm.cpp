#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

const char *in_file_name = "kperm.in";
const char *out_file_name = "kperm.out";
const int MOD = 666013;

using namespace std;

ifstream in_file;
ofstream out_file;

int N, K;
long long *factorial;

void die(bool assertion, const char *message)
{
    if (assertion) {
        fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void get_factorial()
{

	factorial = new long long[N + 1];

    factorial[0] = 1LL;
    for (int i = 1; i <= N; i++)
    	factorial[i] = 1LL * (factorial[i - 1] * i) % MOD;

}

int pow(long long a, int p)
{
    long long rez = 1;

    while (p) {
    	if (p & 1)
    		rez = (1LL * rez * a) % MOD;
    	a = (1LL * a * a) % MOD;
    	p >>= 1;
    }

    return rez;

}

int solve()
{
	int a, b, c, d;

	if ((K % 2) == 0)
		return 0;

	a = N / K;
	b = N % K;

	if (b == 0)
		c = a;
	else
		c = a + 1;

	d = (K - b);

	return (1LL * ((1LL * pow(factorial[c], b) * factorial[b]) % MOD)
			    * ((1LL * pow(factorial[a], d) * factorial[d]) % MOD)) % MOD;

}

int main()
{

    in_file.open(in_file_name, ios::in);
    die(!in_file, "Error opening file for reading");

    out_file.open(out_file_name, ios::out);
    die(!out_file, "Error opening file for writing");

    in_file >> N >> K;

    get_factorial();

    out_file << solve();

    in_file.close();
    out_file.close();

    delete []factorial;

    return 0;
}
