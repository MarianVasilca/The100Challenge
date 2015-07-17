#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 9999999
#define SIZE 1005

const char *in_file_name = "energii.in";
const char *out_file_name = "energii.out";

using namespace std;

ifstream in_file;
ofstream out_file;

/* G - numarul de generatoare */
/* W - cantitatea de energie necesara */
int G, W;
int table[1005][5005];
vector<pair <int, int> > *generators;

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
	int energy, cost;

	in_file >> G >> W;

	generators = new vector<pair <int, int> >[G+1];

	for (int i = 1; i <= G; i++) {
		in_file >> energy >> cost;
		generators[i].push_back(make_pair(energy, cost));
	}

}

int get_result()
{

	int energy, cost;

	for (int i = 0; i <= G; i++)
		for (int j = 1; j <= W; j++)
			table[i][j] = MAX;

	for (int i = 1; i <= G; i++) {

		energy = generators[i][0].first;
		cost = generators[i][0].second;

		for (int j = 1; j <= W; j++) {

			if (energy <= j) {
				table[i][j] = min(table[i-1][j], table[i-1][j - energy] + cost);
			} else {
				table[i][j] = min(table[i-1][j], cost);
			}
		}
	}

	return table[G][W] == MAX ? -1 : table[G][W];
}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	out_file << get_result();

	in_file.close();
	out_file.close();

	delete []generators;

	return 0;
}