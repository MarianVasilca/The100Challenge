#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const char *in_file_name = "text.in";
const char *out_file_name = "text.out";

using namespace std;

ifstream in_file;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int get_medium_length()
{
	int numLetters = 0, numWords = 0;
	char ch;
	bool flag = true;

	while (in_file >> noskipws >> ch) {
		if (isalpha(ch)) {

		 	numLetters++;

		 	if (flag)
		 		numWords++;

		 	flag = false;
		 }
		else
		 	flag = true;
	}

	return numLetters/numWords;
}

int main()
{

	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	out_file << get_medium_length();

	in_file.close();
	out_file.close();

	return 0;
}