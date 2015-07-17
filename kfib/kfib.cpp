#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#define SIZE 2
#define MOD 666013

const char *in_file_name = "kfib.in";
const char *out_file_name = "kfib.out";

int N;
int Z[SIZE][SIZE] = {{0,1},{1,1}};
int sol[SIZE][SIZE];

using namespace std;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void clear_matrix(int a[][SIZE])
{
	memset(a, 0, sizeof(int) * SIZE * SIZE);
}

void copy_matrix(int a[][SIZE], int b[][SIZE])
{
	memcpy(a, b, sizeof(int) * SIZE * SIZE);
}

void print_matrix(int a[][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void multiply(int a[][SIZE], int b[][SIZE], int c[][SIZE])
{

	int i, j, k;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;

}

void kfib(int power)
{
	int aux[SIZE][SIZE], c[SIZE][SIZE];

	copy_matrix(c, Z);
	sol[0][0] = sol[1][1] = 1;

	for (int i = 0; (1 << i) <= power; i++) {
		if (power & (1 << i)) {
			clear_matrix(aux);
			multiply(sol, c, aux);
			copy_matrix(sol, aux);
		}

		clear_matrix(aux);
		multiply(c, c, aux);
		copy_matrix(c, aux);

	}

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

	kfib(N - 1);

	out_file << sol[1][1];

	in_file.close();
	out_file.close();

	return 0;
}