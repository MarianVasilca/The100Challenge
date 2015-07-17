#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

const char *in_file_name = "secv.in";
const char *out_file_name = "secv.out";
const int maxim = 5000;

using namespace std;

ifstream in_file;
ofstream out_file;

int *values, *aux, *numbers;
int N;

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

	in_file >> N;

	values = new int[N + 1];
	aux = new int[N + 1];
	numbers = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		in_file >> values[i];
		aux[i] = values[i];
	}
}

int solve() {
	int counter = 0, best = maxim, length = 0;

	sort(aux + 1, aux + N + 1);

	aux[0] = -1;

	for (int i = 1; i <= N; i++) {
		if (aux[i] != aux[i - 1]) {
			counter++;
			numbers[counter] = aux[i];
		}
	}

	if (counter == 1)
		return 1;

	for (int i = 1; i <= N; i++) {
		if (values[i] == numbers[1]) {
			length = 1;
			for (int j = i + 1; j <= N; j++) {
				if (values[j] == numbers[length + 1])
					length++;

				if (length == counter) {
					if (j - i + 1 < best)
						best = j - i + 1;
					break;
				}
			}
		}
	}

	if (best == maxim)
		return -1;
	else
		return best;

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	out_file << solve();

	in_file.close();
	out_file.close();

	delete []values;
	delete []aux;
	delete []numbers;

	return 0;
}
