#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "combinari.in";
const char *out_file_name = "combinari.out";
int N, M;
int *values;
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
	for (int i = 1; i <= M; i++)
		fprintf(out_file, "%d ", values[i]);
	fprintf(out_file, "\n");
}

void bkt_combinari(int K)
{
	/* K - pe ce pozitie putem sa scrie in vectorul de valori */
	/* M - cat de mare este o combinare */

	if (K > M) {
		write_values();
		return;
	}

	/* se pleaca de la ultima (valoare + 1) pana la o valoare
	care nu depaseste anumite limite */
	for (int i = values[K - 1] + 1; i <= N - (M - K); i++) {
		values[K] = i;
		bkt_combinari(K + 1);
	}

}

int main()
{

	string line;
	ifstream in_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	in_file >> N;
	in_file >> M;

	values = new int[N+1];

	bkt_combinari(1);

	in_file.close();
	fclose(out_file);

	delete []values;

	return 0;
}