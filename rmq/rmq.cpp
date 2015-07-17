#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "rmq.in";
const char *out_file_name = "rmq.out";
const int max_level = 20;
using namespace std;

ifstream in_file;
FILE *out_file;

long int **rmq;
int N, M;
long int *lg;
long int *values;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void write_file()
{

	long int x, y, l, i, diff, sh;

	for (i = 1; i <= M; i++) {
		in_file >> x >> y;

		diff = y - x + 1;
		l = lg[diff];
		sh = diff - (1 << l);

		fprintf(out_file, "%ld\n", min(rmq[l][x], rmq[l][x + sh]));
	}

}

void solve()
{
	long int l;

	for (long int i = 2; i <= N; i++)
		lg[i] = lg[i/2] + 1;

	for (long int i = 1; i <= N; i++)
		rmq[0][i] = values[i];

	for (long int i = 1; (1 << i) <= N; i++)
		for (long int j = 1; j <= N - (1 << i) + 1; j++) {
			l = 1 << (i - 1);
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + l]);
		}

}

void read_file()
{

	in_file >> N >> M;

	rmq = new long int *[max_level];
	for (int i = 0; i < max_level; i++)
		rmq[i] = new long int[N+1]();
	lg = new long int[N+1]();
	values = new long int[N+1];

	for (int i = 1; i <= N; i++)
		in_file >> values[i];

}

int main ()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	read_file();

	solve();

	write_file();

	in_file.close();
	fclose(out_file);

	for (int i = 0; i < max_level; i++)
		delete []rmq[i];
	delete []rmq;
	delete []values;
	delete []lg;

	return 0;
}
