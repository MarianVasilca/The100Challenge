#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

const char *in_file_name = "royfloyd.in";
const char *out_file_name = "royfloyd.out";

using namespace std;

ifstream in_file;
ofstream out_file;
int N, **edges;

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
	// N - noduri
	in_file >> N;

	edges = new int*[N];
	
	for (int i = 0; i < N; ++i)
		edges[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			in_file >> edges[i][j];
			// daca nu exista muche intre doua noduri
			if (i != j && edges[i][j] == 0)
				edges[i][j] = MAX;
		}

}

void roy_floyd()
{

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}

}

void write_file()
{

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			out_file << edges[i][j] << ' ';
		}
		out_file << endl;
	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	roy_floyd();

	write_file();

	in_file.close();
	out_file.close();

	for (int i = 0; i < N; i++)
		delete []edges[i];
	delete []edges;

	return 0;
}