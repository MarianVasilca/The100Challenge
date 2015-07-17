#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>

const char *in_file_name = "dfs.in";
const char *out_file_name = "dfs.out";

using namespace std;

ifstream in_file;
int N, M, S;
bool *visited;
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
	int node1, node2;

	/* N - noduri */
	/* M - muchii */
	in_file >> N >> M;

	edges = new vector<int>[N+1];
	visited = new bool[N+1];

	for (int i = 0; i < M; i++) {
		in_file >> node1 >> node2;
		edges[node1].push_back(node2);
		edges[node2].push_back(node1);
	}

}

void DFS(int node)
{

	visited[node] = true;

	for (int i = 0; i < (int)edges[node].size(); i++)
		if (visited[edges[node][i]] == false)
			DFS(edges[node][i]);

}


int main()
{
	ofstream out_file;
	int cnx = 0;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			cnx++;
			DFS(i);
		}
	}

	out_file << cnx;

	in_file.close();
	out_file.close();

	delete []edges;
	delete []visited;

	return 0;
}