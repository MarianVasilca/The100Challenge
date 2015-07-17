#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

const char *in_file_name = "reuniune.in";
const char *out_file_name = "reuniune.out";

class Dreptunghi
{
	public:
		long long x1, y1, x2, y2;

	static void Intersection(Dreptunghi d1, Dreptunghi d2, Dreptunghi &d3) {
		
		d3.x1 = max(d1.x1, d2.x1);
		d3.y1 = max(d1.y1, d2.y1);
		d3.x2 = min(d1.x2, d2.x2);
		d3.y2 = min(d1.y2, d2.y2);

		if (d3.x1 > d3.x2 || d3.y1 > d3.y2) {
			d3.x1 = 0.0L;
			d3.y1 = 0.0L;
			d3.x2 = 0.0L;
			d3.y2 = 0.0L;
		}
	}

	long long Area() {
		return  1LL * (x2 - x1) * (y2 - y1);
	}

	long long Perimeter() {
		return 2LL * ((x2 - x1) + (y2 - y1));
	}

};

Dreptunghi d1, d2, d3, i1, i2, i3, i4;

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int main()
{

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> d1.x1 >> d1.y1 >> d1.x2 >> d1.y2;
	in_file >> d2.x1 >> d2.y1 >> d2.x2 >> d2.y2;
	in_file >> d3.x1 >> d3.y1 >> d3.x2 >> d3.y2;

	Dreptunghi::Intersection(d1, d2, i1);
	Dreptunghi::Intersection(d1, d3, i2);
	Dreptunghi::Intersection(d2, d3, i3);
	Dreptunghi::Intersection(i1, d3, i4);

	out_file << d1.Area() + d2.Area() + d3.Area() - i1.Area() - i2.Area() - 
		i3.Area() + i4.Area() << ' ';
	out_file << d1.Perimeter() + d2.Perimeter() + d3.Perimeter() - i1.Perimeter() - 
		i2.Perimeter() - i3.Perimeter() + i4.Perimeter() << ' ';

	in_file.close();
	out_file.close();

	return 0;

}