#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const char *in_file_name = "stirling.in";
const char *out_file_name = "stirling.out";
const int mod = 98999;
const int size = 201;

using namespace std;

int **s, **S;

ifstream in_file;
FILE *out_file;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void get_s_function()
{

	s[1][1] = 1;

	for (int i = 2; i < size; i++)
		for (int j = 1; j <= i; j++)
			s[i][j] = (s[i-1][j-1] - (i-1) * s[i-1][j]) % mod;

}

void get_S_function()
{

	S[1][1] = 1;

	for (int i = 2; i < size; i++)
		for (int j = 1; j <= i; j++)
			 S[i][j] = (S[i-1][j-1] + j * S[i-1][j]) % mod;

}

int main()
{
	// teste
	int T, type, n, m;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen (out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	s = new int*[size];
	S = new int*[size];
	for (int i = 0; i < size; i++) {
		s[i] = new int[size];
		S[i] = new int[size];
	}

	get_s_function();

	get_S_function();

	in_file >> T;

	for (int i = 0; i < T; i++) {
		in_file >> type >> n >> m;
		if (type == 1)
			fprintf(out_file, "%d\n", s[n][m]);
		else if (type == 2)
			fprintf(out_file, "%d\n", S[n][m]);
	}

	in_file.close();
	fclose(out_file);

	for (int i = 0; i < size; i++) {
		delete []s[i];
		delete []S[i];
	}

	delete []s;
	delete []S;

	return 0;
}