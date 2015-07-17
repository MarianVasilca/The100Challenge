#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>

#define MAX 100005; 
int phi[100005];

using namespace std;

const char *in_file_name = "sum.in";
const char *out_file_name = "sum.out";

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void set_phi()
{

	int N = MAX;

	/* un nr prim n este prim fata de n-1 numere */
	for (int i = 1; i < N; i++)
		phi[i] = i - 1;

	/* fie m un multiplu al lui n. m nu este prim fata de toate numerele 
	care sunt prime fata de n */
	for (int i = 2; i < N; i++)
		for (int j = i+i; j < N; j += i)
			phi[j] -= phi[i];

}


int main()
{
	int N, x;

	string line;
	ifstream in_file;
	FILE *out;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out = fopen(out_file_name, "w");

	getline(in_file, line);
	N = atoi(line.c_str());

	set_phi();

	for (int i = 0; i < N; i++) {

		getline(in_file, line);
		x = atoi(line.c_str());

		/* phi[x] - numarul de numere prime cu x, mai mici decat x */
		/* vor exista phi[x] perechi de numere a caror suma va fi 2 * x */
		fprintf(out, "%lld\n", 2LL * x * phi[x]);

	}

	in_file.close();
	fclose(out);

	return 0;
}