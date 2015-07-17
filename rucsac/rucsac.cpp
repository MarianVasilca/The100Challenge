#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

const char *in_file_name = "rucsac.in";
const char *out_file_name = "rucsac.out";

int N, G;
int *weights, *profit;
ifstream in_file;
ofstream out_file;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void read_input()
{
	string line;

	getline(in_file, line);

	N = atoi(strtok(&line[0], " "));
	G = atoi(strtok(NULL, "\n "));

	weights = new int[N+1];
	profit = new int[N+1];

	for (int i = 1; i <= N; i++) {

		getline(in_file, line);

		weights[i] = atoi(strtok(&line[0], " "));
		profit[i] = atoi(strtok(NULL, "\n "));
	}

}

int get_max_bidimensional()
{
	int table[N+1][G+1], total_energy = 0;;

	memset(table, 0, sizeof table);

 /* table reprezinta cel mai bun cost obtinut pentru 
 primele i obiecte, avand greutatea maxim cw. */
	for (int i = 1; i <= N; i++) {
		for (int cw = 0; cw <= G; cw++) {

			table[i][cw] = table[i - 1][cw];

			if (weights[i] <= cw) {
				table[i][cw] = max(table[i][cw], 
					table[i - 1][cw - weights[i]] + profit[i]);
			}
		}
	}

	return table[N][G];
}

int get_max()
{

	int table[2][G+1], last = 0;
	memset(table, 0, sizeof table);

	for (int i = 1; i <= N; i++, last = 1 - last) {
		for (int cw = 0; cw <= G; cw++) {

			table[1 - last][cw] = table[last][cw];

			if (weights[i] <= cw)
				table[1 - last][cw] = max(table[1 - last][cw], 
					table[last][cw - weights[i]] + profit[i]);
		}
	}

	return table[last][G];

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_input();

	out_file << get_max();

	delete []weights;
	delete []profit;

	return 0;
}