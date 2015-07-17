#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

#define int64 long long
#define uint64 unsigned long long

const char *in_file_name = "cmap.in";
const char *out_file_name = "cmap.out";
const uint64 inf = (1ULL << 63) - 1ULL;
const int64 MAX_N = 100005;

using namespace std;

ifstream in_file;
ofstream out_file;

int N;
vector< pair<int64, int64> > points;
vector < pair<int64, int64> > v_points;
vector < pair<int64, int64> > V(MAX_N);

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int64 dist(const pair <int64, int64>& a, const pair <int64, int64>& b) {
    return (a.first - b.first) * (a.first - b.first) +
    	(a.second - b.second) * (a.second - b.second);
}

int64 solve(int left, int right)
{

	if (left >= right -1)
		return inf;
	else if (right - left == 2) {
		if (v_points[left] > v_points[left + 1])
			swap(v_points[left], v_points[left + 1]);
		int64 ret = dist(points[left], points[left + 1]);
		return ret;
	}

	int middle = (left + right) / 2;
	int64 result = min(solve(left, middle), solve(middle, right));

	merge(v_points.begin() + left, v_points.begin() + middle,
		v_points.begin() + middle, v_points.begin() + right, V.begin());

    copy(V.begin(), V.begin() + (right - left), v_points.begin() + left);


	int size = 0;

	for (int i = left; i < right; i++) {
		if (abs(v_points[i].second - points[middle].first) <= result)
			V[size++] = v_points[i];
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size && (j - i) < 8; j++)
			result = min(result, dist(V[i], V[j]));
	}

	return result;

}

void read_file()
{
	int64 x = 0.0, y = 0.0;

	in_file >> N;

	for (int i = 0; i < N; i++) {
		in_file >> x >> y;
		points.push_back(make_pair(x, y));
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < N; i++)
		v_points.push_back(make_pair(points[i].second,
			points[i].first));

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	out_file.precision(6);

	out_file << fixed << sqrt(solve(0, N));

	in_file.close();
	out_file.close();

	return 0;
}
