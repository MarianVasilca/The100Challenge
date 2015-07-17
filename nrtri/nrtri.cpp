#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *in_file_name = "nrtri.in";
const char *out_file_name = "nrtri.out";

ifstream in_file;
ofstream out_file;
int N, *stick_length;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void merge(int left, int mid, int right)
{

	register int *copy = new int[right - left + 1];
	register int i, j, k, r, size;

	r = left;
	i = 0;
	j = mid + 1;

	while ((r <= mid) && (j <= right)) {

		if (stick_length[r] <= stick_length[j]) {
			copy[i] = stick_length[r];
			r++;
		} else {
			copy[i] = stick_length[j];
			j++;
		}
		i++;
	}

	if (r > mid) {
		for (k = j; k <= right; k++) {
			copy[i] = stick_length[k];
			i++;
		}
	} else {

		for (k = r; k <= mid; k++) {
			copy[i] = stick_length[k];
			i++;
		}
	}

	size = right - left;
	for (k = 0; k <= size; k++)
		stick_length[k + left] = copy[k];

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

void read_file()
{

	in_file >> N;
	stick_length = new int[N];

	for (int i = 0; i < N; i++)
		in_file >> stick_length[i];

	merge_sort(0, N - 1);
}

int get_result(int i, int j)
{

	int middle, right = N - 1, left = j + 1;

	while (left <= right) {

		middle = (left + right) / 2;

		if (stick_length[i] + stick_length[j] >= stick_length[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}

	return right;

}

int main()
{
	int result = 0;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	for (int i = 0; i < N -1; i++)
		for (int j = i + 1; j < N; j++)
			result += get_result(i, j) - j;

	out_file << result;

	in_file.close();
	out_file.close();

	delete []stick_length;

	return 0;
}