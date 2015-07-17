#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>

const char *in_file_name = "maxflow.in";
const char *out_file_name = "maxflow.out";
const int my_max = 99999999;

using namespace std;

ifstream in_file;

int no_nodes, no_edges;

vector <int> *edges;
int **costs;
int **flux;
bool *visited;
int *dist;
int *parent;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int BF()
{

	int node, V;

	for (int i = 0; i <= no_nodes; i++)
		visited[i] = false;

	visited[1] = true;
	dist[0] = 1;
	dist[1] = 1;

	for (int i = 1; i <= dist[0]; i++) {

		node = dist[i];
		if (node == no_nodes)
			continue;

		for (int j = 0; j < (int)edges[node].size(); j++) {

			V = edges[node][j];

			if ((costs[node][V] == flux[node][V]) || (visited[V]) > 0)
				continue;
			visited[V] = true;
			dist[++dist[0]] = V;
			parent[V] = node;

		}
	}

	return visited[no_nodes];

}

void read_file()
{
	int from, to, cost;

	in_file >> no_nodes >> no_edges;

	edges = new vector<int>[no_nodes + 1];
	costs = new int*[no_nodes + 1];
	flux = new int*[no_nodes + 1];
	visited = new bool[no_nodes + 1];
	dist = new int[no_nodes + 1];
	parent = new int[no_nodes + 1];

	for (int i = 0; i <= no_nodes; i++) {
		dist[i] = 0;
		costs[i] = new int[no_nodes + 1];
		flux[i] = new int[no_nodes + 1];
		for (int j = 0; j <= no_nodes; j++) {
			costs[i][j] = 0;
			flux[i][j] = 0;
		}
	}

	for (int i = 0; i < no_edges; i++) {
		in_file >> from >> to >> cost;
		edges[from].push_back(to);
		edges[to].push_back(from);
		costs[from][to] = cost;
	}

}

int main()
{
	int flow = 0, node, flux_min;;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();


	while (BF()) {
		for (int i = 0; i < (int)edges[no_nodes].size(); i++) {

			node = edges[no_nodes][i];

			if (flux[node][no_nodes] == costs[node][no_nodes] ||
				visited[node] == false)
				continue;
			parent[no_nodes] = node;

			flux_min = my_max;

			for (node = no_nodes; node != 1; node = parent[node])
				flux_min = min(flux_min, costs[parent[node]][node] -
					flux[parent[node]][node]);

			if (flux_min == 0)
				continue;

			for (node = no_nodes; node != 1; node = parent[node]) {
				flux[parent[node]][node] += flux_min;
				flux[node][parent[node]] -= flux_min;
			}

			flow += flux_min;

		}

	}

	out_file << flow << endl;

	in_file.close();
	out_file.close();

	delete []edges;
	for (int i = 0; i <= no_nodes; i++) {
		delete []flux[i];
		delete []costs[i];
	}
	delete []costs;
	delete []flux;
	delete []visited;
	delete []dist;
	delete []parent;

	return 0;
}