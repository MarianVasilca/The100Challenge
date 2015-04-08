#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *in_file_name = "cuburi3.in";
const char *out_file_name = "cuburi3.out";


int main()
{

	string line;
	int N;
	char **weight;
	char **length;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	out_file.open(out_file_name, ios::out);

	if (!in_file) {
		cout << "Error opening file for reading" << endl;
		return -1;
	}

	if (!out_file) {
		cout << "Error opening file for writing" << endl;
		return -2;
	}

	/* get first line */
	getline(in_file, line);
	N = atoi(line.c_str());

	weight = new char*[N];
	length = new char*[N];

	for (int i = 0; i < N; i++) {

		getline(in_file, line);

		length[i] = strdup(strtok(&line[0], " "));
		weight[i] = strdup(strtok(NULL, "\n "));

	}

	for (int i = 0; i < N; i++)
		cout << length[i] << " " << weight[i] << endl;

	return 0;
}