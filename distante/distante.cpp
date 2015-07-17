#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


const char *in_file_name = "distante.in";
const char *out_file_name = "distante.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int T, N, M, S;
int *dist;

void die(bool assertion, const char *message)
{
    if (assertion) {
        fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void solve()
{
    int from, to, cost;
    bool lower;

    in_file >> T;

    while (T) {

        lower = false;

        in_file >> N >> M >> S;
        dist = new int[N + 1]();

        for (int i = 1; i <= N; i++)
            in_file >> dist[i];

        for (int i = 1; i <= M; i++) {
            in_file >> from >> to >> cost;

            if ((dist[from] > dist[to] + cost) ||
                (dist[to] > dist[from] + cost))
                    lower = true;
        }

        if (lower == false && !dist[S])
            out_file << "DA\n";
        else
            out_file << "NU\n";

        delete []dist;

        T--;
    }

}

int main()
{

    in_file.open(in_file_name, ios::in);
    die(!in_file, "Error opening file for reading");

    out_file.open(out_file_name, ios::out);
    die(!out_file, "Error opening file for writing");

    solve();

    in_file.close();
    out_file.close();

    return 0;
}
