#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>

const char *in_file_name = "bfs.in";
const char *out_file_name = "bfs.out";

using namespace std;

ifstream in_file;
int N, M, S;
int *distances;
vector<int> *edges;


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
	int from, to;

	in_file >> N >> M >> S;

	edges = new vector<int>[N+1];
	distances = new int[N+1];

	for (int i = 0; i < M; i++) {
		in_file >> from >> to;
		edges[from].push_back(to);
	}

	for (int i = 1; i <= N; i++)
		distances[i] = -1;

}

void BFS()
{
	int current_node;
	queue<int> Q;

	Q.push(S);
	distances[S] = 0;

	while (!Q.empty()) {

		current_node = Q.front();
		Q.pop();

		for (int i = 0; i < (int)edges[current_node].size(); i++) {

			if (distances[edges[current_node][i]] == -1) {

				distances[edges[current_node][i]] = distances[current_node] + 1;
				Q.push(edges[current_node][i]);
			}
		}
	}

}

int main()
{
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();
	BFS();

	for (int i = 1; i <= N; i++)
		out_file << distances[i] << ' ';

	in_file.close();
	out_file.close();

	delete []edges;
	delete []distances;

	return 0;
}