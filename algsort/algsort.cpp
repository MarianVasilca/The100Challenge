#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>

const char *in_file_name = "algsort.in";
const char *out_file_name = "algsort.out";
const char *heapsort = "heapsort";
const char *introsort = "introsort";
const char *mergesort = "mergesort";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M;
int *vector;

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
	
	vector = new int[N];

	for (int i = 0; i < N; i++)
		in_file >> vector[i];
}

void write_file()
{
	for (int i = 0; i < N; i++)
		out_file << vector[i] << " ";
}

void merge(int left, int mid, int right)
{

	register int *copy = new int[right - left + 1];
	register int i, j, k, r, size;

	r = left;
	i = 0;
	j = mid + 1;

	while ((r <= mid) && (j <= right)) {

		if (vector[r] <= vector[j]) {
			copy[i] = vector[r];
			r++;
		} else {
			copy[i] = vector[j];
			j++;
		}
		i++;
	}

	if (r > mid) {
		for (k = j; k <= right; k++) {
			copy[i] = vector[k];
			i++;
		}
	} else {

		for (k = r; k <= mid; k++) {
			copy[i] = vector[k];
			i++;
		}
	}

	size = right - left;
	for (k = 0; k <= size; k++)
		vector[k + left] = copy[k];

	delete []copy;

}

void merge_sort(int left, int right)
{

	int mid;
	if (left < right) {

		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}

}

void heapsort_function()
{

	register int temp;
	register int n = N, parent = N / 2, index, child;

	while (1) {

		if (parent > 0) {
			temp = vector[--parent];
		} else {
			n--;
			if (n == 0)
				return;

			temp = vector[n];
			vector[n] = vector[0];
		}

		index = parent;
		child = index * 2 + 1;

		while (child < n) {

			if (child + 1 < n && vector[child + 1] > vector[child])
				child++;

			if (vector[child] > temp) {
				vector[index] = vector[child];
				index = child;
				child = index * 2 + 1;
			} else break;
		}

		vector[index] = temp;
	}

}

void sort(const char *sort_type)
{
	if (strcmp(sort_type, mergesort) == 0) {
		
		merge_sort(0, N - 1);

	} else if (strcmp(sort_type, heapsort) == 0) {
		heapsort_function();

	} else if (strcmp(sort_type, introsort) == 0) {
		cout << "Ai ales introsort" << endl;

	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	//sort(mergesort);
	sort(heapsort);
	//sort(introsort);

	write_file();

	in_file.close();
	out_file.close();

	delete []vector;

	return 0;
}