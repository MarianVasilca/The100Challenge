#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

const char *in_file_name = "aprindere.in";
const char *out_file_name = "aprindere.out";

using namespace std;

ifstream in_file;
ofstream out_file;

int N, M;
bool *room;
int *timer;
vector < int > *changer;

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
	int room_no, no_rooms, temp_room;

	in_file >> N >> M;

	room = new bool[N];
	timer = new int[N];
	changer = new vector < int > [N];

	for (int i = 0; i < N; i++)
		in_file >> room[i];

	for (int i = 0; i < M; i++) {

		in_file >> room_no;
		in_file >> timer[room_no] >> no_rooms;

		for (int j = 0; j < no_rooms; j++) {
			in_file >> temp_room;
			changer[room_no].push_back(temp_room);
		}
	}


}

int solve()
{
	int result = 0;

	for (int i = 0; i < N; i++) {
		if(room[i] == false) {
			result += timer[i];
			for (int j = 0; j < (int)changer[i].size(); j++) {
				room[changer[i][j]] = !room[changer[i][j]];
			}
		}
	}

	return result;
}


int main()
{

    in_file.open(in_file_name, ios::in);
    die(!in_file, "Error opening file for reading");

    out_file.open(out_file_name, ios::out);
    die(!out_file, "Error opening file for writing");

    read_file();

    out_file << solve();

    in_file.close();
    out_file.close();

    return 0;
}
