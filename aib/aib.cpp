#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const char *in_file_name = "aib.in";
const char *out_file_name = "aib.out";
int *tree;
int N, M;

using namespace std;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void add_value(int poz, int val)
{

    while (poz <= N){
        tree[poz] += val;
        // cout << poz << " " << -poz << endl;
        poz += (poz & -poz);
        // cout << poz << endl << endl;
}
	cout << endl;

}

int main()
{
	int val;
	ifstream in_file;
	FILE *out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	in_file >> N;
	in_file >> M;

	tree = new int[N+1];

	for (int i = 1; i <= N; i++) {
		in_file >> val;
		add_value(i, val);
		for (int j = 0; j <= N; j++)
			cout << tree[j] << " ";
	}



	in_file.close();
	fclose(out_file);

	return 0;
}