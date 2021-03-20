#include "Line.h"

Line::Line(int N = 1)
{
	v = new double[N];

	for (int j = 0; j < N; j++)
		v[j] = 0;
}
double& Line::operator[] (int j) { return v[j]; }

Line::Line()
{
	v = new double[1];
	v[0] = 0;
}