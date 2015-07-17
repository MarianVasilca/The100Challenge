#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "ciur.in";
const char *out_file_name = "ciur.out";

bool *numbers;
int N;

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
	int result = 0;

	for (int i = 2; i <= N; i++) {

		if (numbers[i] == false) {
			result++;

			for (int j = 2*i; j <= N; j +=i)
				numbers[j] = true;
		}
	}

	return result;

}

int main()
{

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> N;

	numbers = new bool[N + 1];

	out_file << get_prime_numbers(N);

	in_file.close();
	out_file.close();

	delete []numbers;

	return 0;

}