#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <stdlib.h>

const char *in_file_name = "ctc.in";
const char *out_file_name = "ctc.out";

using namespace std;

ifstream in_file;
FILE *out_file;

/* N numbers of nodes */
/* numbers of edges */
int N, M;
vector<int> *edges, index, lowlink, connection;
vector<bool> in_stack;
vector <vector <int> > result;
stack <int> my_stack;
int idx = 0;

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

	int to, from;

	in_file >> N >> M;

	edges = new vector<int>[N];

	for (int i = 0; i < M; i++) {
		in_file >> from >> to;
		edges[from - 1].push_back(to - 1);
	}

	index.resize(N);
	lowlink.resize(N);
	in_stack.resize(N);
	index.assign(N, -1);
	in_stack.assign(N, false);

}

void write_file()
{

	fprintf(out_file, "%d\n", (int) result.size());
	for (int i = 0; i < (int) result.size(); i++) {
		for (int j = 0; j < (int) result[i].size(); j++)
			fprintf(out_file, "%d ", result[i][j] + 1);
		fprintf(out_file, "\n");
	}
}

void tarjan(int n)
{
	int from = n, to, node;
	int size = edges[from].size();

	/* Set the depth index for from to the smallest unused index */
	index[n] = lowlink[n] = idx;
	idx++;

	my_stack.push(n);
	in_stack[n] = true;

	/* Consider successors of from */
	for (int i = 0; i < size; i++) {
		to = edges[from][i];
		if (index[to] == -1) {
			/* Successor to has not yet been visited; recurse on it */
			tarjan(to);
			lowlink[from] = min(lowlink[from], lowlink[to]);
		} else if (in_stack[to])
			/* Successor to is in stack S and hence in the current SCC */
			lowlink[from] = min(lowlink[from], index[to]);
	}

	/* If from is a root node, pop the stack and generate an SCC */
	if (lowlink[from] == index[from]) {

		connection.clear();

		do {

			node = my_stack.top();
			my_stack.pop();
			connection.push_back(node);
			in_stack[node] = false;

		} while (node != from);

		result.push_back(connection);
	}


}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file = fopen (out_file_name, "w");
	die(!out_file, "Error opening file for writing");

	read_file();

	for (int i = 0; i < N; i++)
		if (index[i] == -1)
			tarjan(i);

	write_file();

	in_file.close();
	fclose(out_file);

	delete []edges;

	return 0;
}