#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "divprim.in";
const char *out_file_name = "divprim.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int T, maxim;
vector < pair<int, int> > pairs;
int *numbers;

void die(bool assertion, const char *message)
{
    if (assertion) {
        fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void ciur()
{

	for (int i = 2; i <= maxim; i++) {

		if (numbers[i] == 0) {
			numbers[i]++;

			for (int j = 2*i; j <= maxim; j +=i)
				numbers[j]++;
		}
	}

}

void read_file()
{
	int N, K;

	in_file >> T;

	for (int i = 0; i < T; i++) {
		in_file >> N >> K;
		maxim = max(N, maxim);
		pairs.push_back(make_pair(N, K));
	}

	numbers = new int[maxim + 1]();

}

int main()
{

    in_file.open(in_file_name, ios::in);
    die(!in_file, "Error opening file for reading");

    out_file.open(out_file_name, ios::out);
    die(!out_file, "Error opening file for writing");

    read_file();

    ciur();

    in_file.close();
    out_file.close();

    return 0;
}
