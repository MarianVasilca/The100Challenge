#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

#define RADIX 0xFF
#define RADIX_SIZE 8

using namespace std;

const char *in_file_name = "radixsort.in";
const char *out_file_name = "radixsort.out";

ifstream in_file;
FILE *out_file;

int N, A, B, C;
int *numbers;


void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

inline int get_byte(int x, int byte)
{
	return ((x >> (byte * RADIX_SIZE)) & RADIX);
}

void count_sort(int A[], int B[], int byte)
{
	int new_byte, size;

	size = 1 << RADIX_SIZE;

	int *counter = new int[size]();
	int *index = new int[size];

	for (int i = 0; i < N; i++) {
		new_byte = get_byte(A[i], byte);
		counter[new_byte]++;
	}

	index[0] = 0;

	for (int i = 1; i < size; i++) {
		index[i] = index[i - 1] + counter[i - 1];
	}

	for (int i = 0; i < N; i++) {
		new_byte = get_byte(A[i], byte);
		B[index[new_byte]] = A[i];
		index[new_byte]++;
	}

	delete []counter;
	delete []index;
}

void radix_sort()
{
	int *temp = new int[N];
	int size = (int)sizeof(numbers[0]);

	for (int  i = 0; i < size; i++) {
		if (i % 2 == 0)
			count_sort(numbers, temp, i);
		else
			count_sort(temp, numbers, i);
	}

	delete []temp;
}

void read_file()
{

	in_file >> N >> A >> B >> C;

	numbers = new int[N];

	numbers[0] = B;

	for (int i = 1; i < N; i++)
		numbers[i] = (1LL * A * numbers[i - 1] % C + B) % C;
}

void write_file()
{
	for (int i = 0; i < N; i += 10)
		fprintf(out_file, "%d ", numbers[i]);
	fprintf(out_file, "\n");
}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen(out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	read_file();

	radix_sort();

	// write_file();

	in_file.close();
	fclose(out_file);

	delete []numbers;

	return 0;

}
