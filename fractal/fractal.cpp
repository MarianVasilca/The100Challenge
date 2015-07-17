#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const char *in_file_name = "fractal.in";
const char *out_file_name = "fractal.out";

using namespace std;

ifstream in_file;
ofstream out_file;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int fractal(int k, int x, int y)
{
	int latura_cadran;

	if (k == 0)
		return 0;

	latura_cadran = 1 << (k - 1);

	if (x <= latura_cadran && y <= latura_cadran)
		return fractal(k - 1, y, x);

	if (x <= latura_cadran && y > latura_cadran)
		return latura_cadran * latura_cadran +
			fractal(k - 1, x, y - latura_cadran);

	if (x > latura_cadran && y > latura_cadran)
		return 2 * latura_cadran * latura_cadran +
			fractal(k - 1, x - latura_cadran, y - latura_cadran);

	if (x > latura_cadran && y <= latura_cadran)
		return 3 * latura_cadran * latura_cadran +
			fractal(k - 1, latura_cadran - y + 1, 2 * latura_cadran - x + 1);

	else return 0;

}

int main()
{
	int k, x, y;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> k >> x >> y;

	out_file << fractal(k, x, y);

	in_file.close();
	out_file.close();

	return 0;
}

