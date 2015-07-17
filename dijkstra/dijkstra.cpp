#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>
#include <stdlib.h>

#define MAX 999999

const char *in_file_name = "dijkstra.in";
const char *out_file_name = "dijkstra.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M;
int *dist;
vector<pair <int, int> > *edges;
bool *visited;
queue <int> Q;

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
	/* N - noduri */
	/* M - arce	  */
	int from, to, cost;

	in_file >> N >> M;
	edges = new vector<pair <int, int> >[N+1];
	visited = new bool[N+1];
	dist = new int[N+1];

	for (int i = 0; i < M; i++) {
		in_file >> from >> to >> cost;
		edges[from].push_back(make_pair(to, cost));
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = MAX;
		visited[i] = false;
	}
	dist[1] = 0;

}

void write_file()
{

	for (int i = 2; i <= N; i++)
		out_file << (dist[i] < MAX ? dist[i] : 0) << " ";

}

void dijkstra()
{
	int node, node2, cost;

	while (Q.empty() == false) {

		node = Q.front();
		Q.pop();

		visited[node] = false;

		for (int i = 0; i < (int)edges[node].size(); i++) {

			node2 = edges[node][i].first;
			cost = edges[node][i].second;

			if (dist[node] + cost < dist[node2]) {

				dist[node2] = dist[node] + cost;

				if (visited[node2] == false) {

					Q.push(node2);
					visited[node2] = true;
				}
			}
		}
	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	visited[1] = true;
	Q.push(1);

	dijkstra();

	write_file();

	in_file.close();
	out_file.close();

	delete []edges;
	delete []visited;
	delete []dist;

	return 0;
}
