#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>


const char *in_file_name = "sate.in";
const char *out_file_name = "sate.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M, X, Y;
int *cost;
vector<pair <int, int> > *dist;
queue<int> Q;

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
	int from = 0, to = 0, d = 0;

	in_file >> N >> M >> X >> Y;
	dist = new vector<pair <int, int> >[N + 1]();
	cost = new int[N + 1]();

	for (int i = 0; i < M; i++) {
		in_file >> from >> to >> d;
		dist[from].push_back(make_pair(to, d));
		dist[to].push_back(make_pair(from, -d));
	}

}

void bfs()
{
	int from = 0, to = 0, d = 0;

	Q.push(X);

	if (X == Y)
		return;

	while (Q.empty() == false) {

		from = Q.front();
		Q.pop();

		for (int i = 0; i < (int)dist[from].size(); i++) {
			to = dist[from][i].first;
			d = dist[from][i].second;

			if (cost[to] == 0) {
				cost[to] = cost[from] + d;
				if (to == Y)
					return;
				else
					Q.push(to);
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

    bfs();

    out_file << cost[Y];

    in_file.close();
    out_file.close();

    delete []dist;
    delete []cost;

    return 0;
}
