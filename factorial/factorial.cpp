#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "fact.in";
const char *out_file_name = "fact.out";

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

 int get_number_linear(int P, int N)
 {
 	int count, aux;

 	while (P > 0) {
 	
 	count = 0;

 	N += 5;
 	aux = N;

	 	while (true) {

			if (aux % 5 == 0) {
				count++;
				aux /= 5;
			}
			else
				break;
	 	}

 	P -= count;
 }

 	return N;

 }

 long getFactorial(long n)
 {

 	long count = 0L;

 	while (n >= 5) {

 		count += n / 5;
 		n = n / 5;

 	}

 	return count;

 }

 long get_number(int P)
 {

 	long middle, fact, num = -1, left = 1L, right = 5 * P;

 	while (left <= right) {

 		middle = (right + left) / 2L;

 		fact = getFactorial(middle);

 		if (fact < P)
 			left = middle + 1;
 		else
 			right = middle - 1;
 	}

 	if (getFactorial(left) == P)
 		num = left;

 	return num;

 }


int main()
{
	string line;
	int P, result;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	getline(in_file, line);
	die(!is_valid_int(line.c_str()), "Invaild input");

	P = atoi(line.c_str());
	die(P < 0, "Number must be positive");

	if (P == 0)
		out_file << 1;
	else {
		result = get_number(P);
		out_file << result;
	}

	in_file.close();
	out_file.close();

	return 0;
}
