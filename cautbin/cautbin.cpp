#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *in_file_name = "cautbin.in";
const char *out_file_name = "cautbin.out";

ifstream in_file;
FILE *out_file;
int N, M, *values;

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

	values = new int[N+1];
	for (int i = 1; i <= N; i++)
		in_file >> values[i];

	in_file >> M;

}
/* 0 x - cea mai mare pozitie pe care se afla un element cu valoarea x 
sau -1 daca aceasta valoare nu se gaseste in sir */
int binary_search_0(int left, int right, int value)
{

	int middle;

	while (left <= right) {

		middle = (left + right) / 2;
		if (values[middle] <= value)
			left = middle + 1;
		else
			right = middle - 1;
	}
	middle = (left + right) / 2;

	if (values[middle] > value)
		middle--;
	if (values[middle] == value)
		return middle;
	return -1;

}

/* 1 x - cea mai mare pozitie pe care se afla un element cu valoarea mai mica sau egala cu x in sir. 
Se garanteaza ca cel mai mic numar al sirului este mai mic sau egal decat x  */
int binary_search_1(int left, int right, int value)
{

	int middle;

	while (left < right) {
		middle = (left + right) / 2;
		if (values[middle] <= value)
			left = middle + 1;
		else
			right = middle;
	}

	middle = (left + right) / 2;
	if (values[middle] > value)
		middle--;
	return middle;

}

/* 2 x - cea mai mica pozitie pe care se afla un element cu valoarea mai mare sau egala cu x in sir. 
Se garanteaza ca cel mai mare numar din sir este mai mare sau egal decat x */
int binary_search_2(int left, int right, int value)
{

	int middle;

	while (left < right) {
		middle = (left + right) / 2;
		if (values[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}

	middle = (left + right) / 2;
	if (values[middle] < value)
		middle++;
	return middle;

}

int main()
{
	int type, x; 

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen (out_file_name,"w");
	die(!out_file, "Error opening file for writing");

	read_file();

	for (int i = 0; i < M; i++) {
		in_file >> type >> x;
		if (type == 0)
			fprintf(out_file, "%d\n", binary_search_0(1, N, x));
		if (type == 1)
			fprintf(out_file, "%d\n", binary_search_1(1, N, x));
		if (type == 2)
			fprintf(out_file, "%d\n", binary_search_2(1, N, x));
	}

	in_file.close();
	fclose(out_file);

	delete []values;

	return 0;
}
