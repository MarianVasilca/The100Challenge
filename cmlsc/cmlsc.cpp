#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "cmlsc.in";
const char *out_file_name = "cmlsc.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int M, N;
int length;
int *A, *B;
int **matrix;
int *result;

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
	in_file >> M >> N;

	A = new int[M + 1];
	B = new int[N + 1];
	result = new int[max(N, M)];
	matrix = new int*[M + 1];

	for (int i = 0; i <= M; i++) {
		matrix[i] = new int[N + 1]();

		if (i > 0)
			in_file >> A[i];
	}

	for (int i = 1; i <= N; i++)
		in_file >> B[i];

}

void solve()
{

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			if (A[i] == B[j])
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else
				matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);

	for (int i = M, j = N; i > 0; )
		if (A[i] == B[j]) {
			result[length] = A[i];
			i--, j--, length++;
		} else if (matrix[i - 1][j] < matrix[i][j - 1])
			j--;
		else
			i--;

		out_file << length << endl;

		for (int i = length - 1; i >= 0; i--)
			out_file << result[i] << " ";

}

int main()
{

    in_file.open(in_file_name, ios::in);
    die(!in_file, "Error opening file for reading");

    out_file.open(out_file_name, ios::out);
    die(!out_file, "Error opening file for writing");

    read_file();

    solve();

    in_file.close();
    out_file.close();

    for (int i = 0; i <= M; i++)
    	delete [] matrix[i];

    delete []A;
    delete []B;
    delete []matrix;

    return 0;
}
