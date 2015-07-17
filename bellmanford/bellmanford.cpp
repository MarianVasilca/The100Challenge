#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "bellmanford.in";
const char *out_file_name = "bellmanford.out";
const int MAX = 9999999;

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M;
int *dist, *cnt_in_queue;
vector<pair <int, int> > *edges;
vector<int> *edge;
bool *in_queue;
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
	edge = new vector<int>[N+1];
	in_queue = new bool[N+1];
	dist = new int[N+1];
	cnt_in_queue = new int[N+1];

	for (int i = 0; i < M; i++) {
		in_file >> from >> to >> cost;
		edges[from].push_back(make_pair(to, cost));
		edge[from].push_back(to);
	}

	for (int i = 0; i <= N; i++) {
		in_queue[i] = false;
		cnt_in_queue[i] = 0;
	}

	dist[1] = 0;
	for (int i = 2; i <= N; i++)
		dist[i] = MAX;
}

void bellman_ford()
{

	int node, node2, cost;
	bool negative_cycle = false;
	int size;

	while (!Q.empty() && !negative_cycle) {

		node = Q.front();
		Q.pop();

		in_queue[node] = false;

		size = edges[node].size();

		for (int i = 0; i < size; i++) {

			node2 = edges[node][i].first;
			cost = edges[node][i].second;

			if (dist[node2] > dist[node] + cost) {

				dist[node2] = dist[node] + cost;

				if (!in_queue[node2]) {
					if (cnt_in_queue[node2] > N)
						negative_cycle = true;
					else {
						Q.push(node2);
						in_queue[node2] = true;
						cnt_in_queue[node2]++;
					}
				}
			}
		}
	}

	if (negative_cycle) {
		out_file << "Ciclu negativ!";
	}
	else {
		for (int i = 2; i <= N; i++)
			out_file << dist[i] << " ";
	}

}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	in_queue[1] = true;
	Q.push(1);

	/* more like dijkstra */
	bellman_ford();

	in_file.close();
	out_file.close();

	delete []edges;
	delete []edge;
	delete []in_queue;
	delete []dist;
	delete []cnt_in_queue;

	return 0;
}
