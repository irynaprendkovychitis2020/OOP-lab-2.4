#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Line
{
public:
	double* v;

	Line();
	Line(int);
	double& operator [] (int);
};