#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

const char *in_file_name = "asmax.in";
const char *out_file_name = "asmax.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N;	/* numar noduri */
vector<int> *edges;
bool *visited;
int *sum;

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
	int first_node, second_node;

	in_file >> N;
	edges = new vector<int>[N+1];
	visited = new bool[N+1];
	sum = new int[N+1];

	for (int i = 1; i <= N; i++) {
		in_file >> sum[i];
	}

	for (int i = 1; i < N; i++) {
		in_file >> first_node >> second_node;
		edges[first_node].push_back(second_node);
		edges[second_node].push_back(first_node);
	}

}

void DFS(int node)
{

	visited[node] = true;

	for (int i = 0; i < (int)edges[node].size(); i++)
		if (visited[edges[node][i]] == false) {
			DFS(edges[node][i]);
			if (sum[edges[node][i]] > 0)
				sum[node] += sum[edges[node][i]];
		}

}

int main()
{
	int maxim = -9999;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	DFS(1);

	for (int i = 1; i <= N; i++)
		maxim = max(maxim, sum[i]);

	out_file << maxim;

	in_file.close();
	out_file.close();

	delete []edges;
	delete []visited;
	delete []sum;

	return 0;
}
