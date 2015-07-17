#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

#define WHITE 0		/* not visited */
#define GREY 1		/* current visiting */
#define BLACK 2		/* visited */

using namespace std;

const char *in_file_name = "sortaret.in";
const char *out_file_name = "sortaret.out";

struct node {
	int index;
	struct node *next_node;
}node;


ifstream in_file;
ofstream out_file;

struct node **list_neigh;
struct node *address;
int *visited;
int N, M;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void add_edge(int from, int to)
{

	struct node *p = new struct node;
	p->index = to;
	p->next_node = list_neigh[from];
	list_neigh[from] = p;

}

void read_file()
{
	int from, to;

	in_file >> N >> M;

	list_neigh = new struct node*[N + 1];
	visited = new int[N + 1];

	for (int i = 0; i < M; i++) {
		in_file >> from	>> to;
		add_edge(from, to);
	}

}

void push_node(int node_index)
{
	struct node *pnode = new struct node;
	pnode->index = node_index;
	pnode->next_node = address;
	address = pnode;
}

void DF(int node_index)
{
	visited[node_index] = GREY;

	for(struct node *pnode = list_neigh[node_index]; pnode; pnode = pnode->next_node)
		if (visited[pnode->index] == WHITE)
			DF (pnode->index);

	visited[node_index] = BLACK;
	push_node(node_index);
}

void topological_sort()
{

	for (int i = 1; i <= N; i++)
		if (visited[i] == WHITE)
			DF(i);

}

void write_file()
{
	for (struct node *pnode = address; pnode; pnode = pnode->next_node)
		out_file << pnode->index << " ";
}

int main()
{

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	read_file();

	topological_sort();

	write_file();

	in_file.close();
	out_file.close();

	delete []list_neigh;
	delete []visited;

	return 0;

}