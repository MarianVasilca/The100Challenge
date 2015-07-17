#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "permutari.in";
const char *out_file_name = "permutari.out";

int *values, N;
bool *found;
FILE *out_file;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void write_values()
{

	for (int i = 1; i <= N; i++)
		fprintf(out_file, "%d ", values[i]);
	fprintf(out_file, "\n");

}

void bkt_permutari(int K)
{

	if (K > N) {
		write_values();
		return;
	}

	for (int i = 1; i <= N; i++) {

		/* acea valoarea nu a fost folosita */
		if (found[i] == false) {

			values[K] = i;
			found[i] = true;

			bkt_permutari(K + 1);

			/* acea valoare poate fi folosita din nou */
			found[i] = false;
		}
	}

}


int main()
{

	ifstream in_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	in_file >> N;

	values = new int[N+1];
	found = new bool[N+1];

	bkt_permutari(1);

	in_file.close();
	fclose(out_file);

	delete []values;

	return 0;
}