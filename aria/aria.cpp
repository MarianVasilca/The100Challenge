#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "aria.in";
const char *out_file_name = "aria.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N;
vector< pair<double, double> > points;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

double solve()
{
	double result = 0.0;

	for (int i = 0; i < N; i++)
		result += points[i].first * points[i + 1].second
				- points[i].second * points[i + 1].first;

	if (result < 0)
		result *= -1.0;

	result /= 2.0;

	return result;
}

void read_file()
{
	double x = 0.0, y = 0.0;

	in_file >> N;

	for (int i = 0; i < N; i++) {
		in_file >> x >> y;
		points.push_back(make_pair(x, y));
	}

	points.push_back(make_pair(points[0].first, points[0].second));
}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	out_file.precision(6);

	out_file << fixed << solve();

	in_file.close();
	out_file.close();

	return 0;
}
