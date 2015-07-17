#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "arbint.in";
const char *out_file_name = "arbint.out";

using namespace std;

ifstream in_file;
FILE *out_file;

int *maxArb;
int N, M;
int maxim;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void querry(int node, int left, int right, int start, int finish)
{

	if (start <= left && right <= finish) {
		if (maxim < maxArb[node])
			maxim = maxArb[node];

		return;
	}

	int middle = (right + left) / 2;

	if (start <= middle)
		querry(2 * node, left, middle, start, finish);
	if (middle < finish)
		querry(2 * node + 1, middle + 1, right, start, finish);

}

void update(int node, int left, int right, int position, int value)
{

	if (left == right) {
		maxArb[node] = value;
		return;
	}

	int middle = (left + right) / 2;

	if (position <= middle)
		update(2 * node, left, middle, position, value);
	else
		update(2 * node + 1, middle + 1, right, position, value);

	maxArb[node] = max(maxArb[2 * node], maxArb[2 * node + 1]);

}

void read_file()
{
	int op_type, a, b, position, value, start, finish;
	/* N - elemente */
	/* M operatii */
	in_file >> N >> M;

	maxArb = new int[5 * N]();

	for (int i = 1; i <= N; i++) {
		position = i;
		in_file >> value;
		update(1, 1, N, position, value);
	}

	for (int i = 1; i <= M; i++) {
		in_file >> op_type >> a >> b;

		if (op_type == 0) {

			maxim = -1;
			start = a;
			finish = b;

			querry(1, 1, N, start, finish);

			fprintf(out_file, "%d\n", maxim);

		} else if (op_type == 1) {
			position = a;
			value = b;
			update(1, 1, N, position, value);
		}
	}

}

int main ()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	read_file();

	in_file.close();
	fclose(out_file);

	delete []maxArb;

	return 0;
}
