#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char *in_file_name = "ssm.in";
const char *out_file_name = "ssm.out";

ifstream in_file;
ofstream out_file;
int N;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void do_ssm()
{
	int bestSum = -int(2e9), sum = 0, begin = 0, end = 0, index, S;

	in_file >> N;

	for (int i = 1; i <= N; i++) {
		in_file >> S;

        if (sum < 0) {
            sum = S;
            index = i;
        }
        else
            sum += S;

        if (bestSum < sum) {
            bestSum = sum; 
           	begin = index;
           	end = i;
        }
   
	}

	out_file << bestSum << " " << begin << " " << end;

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	do_ssm();

	in_file.close();
	out_file.close();

	return 0;
}

