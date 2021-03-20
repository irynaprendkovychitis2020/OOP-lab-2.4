#pragma once
#include "Line.h"

class Matrix
{
private:
	int N;
	Line* m;
public:
	Matrix();
	Matrix(int);
	Matrix(int N, Line*);

	int GetN() const;

	Line& operator[] (int);
	Matrix& operator = (const Matrix&);
	friend ostream& operator << (ostream&, const Matrix&);
	friend istream& operator >> (istream&, Matrix&);
	operator string() const;

	friend void operator + (Matrix&, Matrix&);
	friend bool operator == (Matrix&, Matrix&);

	double Norm();
	void Comparison(Matrix&, Matrix&);
	int findMax();
	int findMin();


	~Matrix();
};