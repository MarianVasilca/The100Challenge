#include    <iostream>
#include    <fstream>
#include    <vector>

using namespace std;

ifstream fin("aprindere.in");
ofstream fout("aprindere.out");

const int NMax = 1005;

int N, M, T[NMax];
bool Room[NMax];

vector < int > V[NMax];

int Result;

void Read()
{
    fin >> N >> M;

    for(int i = 0; i < N; i++)
        fin >> Room[ i ];

    for(int i = 0; i < M; i++)
    {
        int room, total_rooms, temp_room;

        fin >> room; fin >> T[ room ] >> total_rooms;
        for(int j = 0; j < total_rooms; j++)
        {
            fin >> temp_room;
            V[room].push_back(temp_room);
        }
    }
}

void Solve()
{
    for(int i = 0; i < N; i++)
    {
        if(!Room [ i ])
        {
            Result += T[ i ];
            for(unsigned int j = 0; j < V[ i ].size(); j++)
            {
                int Neighbor = V[ i ][ j ];
                Room [ Neighbor ] = !Room[ Neighbor ];
            }
        }
    }
    fout << Result << "\n";
}

int main()
{
    Read();
    Solve();
    return 0;
}