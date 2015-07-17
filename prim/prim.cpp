#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "prim.in";
const char *out_file_name = "prim.out";

bool *numbers;

/* 1318699 is the 100.000th prime number*/
#define MAX 1318700

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

bool is_valid_int(const char *str)
{
	while (*str)
	{
		if(!isdigit(*str))
			return false;
		else
			str++;
	}

	return true;

}

int get_prime_numbers(int K)
{
	int position = 0, result = 0;

	for (int i = 2; i < MAX; i++) {

		if(position >= K)
			break;

		if (numbers[i] == false) {
			result = i;
			position++;

			for (int j = 2*i; j <= MAX; j +=i)
				numbers[j] = true;
		}
	}

	return result;

}


int main()
{
	string line;
	int K;
	long long result;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	getline(in_file, line);
	die(!(is_valid_int(line.c_str())), "Invalid input");

	K = atoi(line.c_str());
	die(K < 1, "Invalid input");

	numbers = new bool[MAX];

	result = get_prime_numbers(K + 1);

	out_file << (result * result * 1LL);

	in_file.close();
	out_file.close();

	delete []numbers;

	return 0;

}
