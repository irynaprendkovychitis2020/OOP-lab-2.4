#include "Matrix.h"

Matrix::Matrix()
{
	N = 1;

	m = new Line[N];
	m[0] = Line(N);
}
Matrix::Matrix(int N = 1)
{
	this->N = N < 1 ? 1 : N;

	m = new Line[this->N];
	for (int i = 0; i < this->N; i++) { m[i] = Line(this->N); }
}
Matrix::Matrix(int N, Line* A)
{
	this->N = N;
	m = A;
}

int Matrix::GetN() const { return N; }

Line& Matrix::operator[] (int i) { return m[i]; }
Matrix& Matrix::operator = (const Matrix& A)
{
	N = A.N;
	m = A.m;
	return *this;
}
Matrix::operator string() const
{
	stringstream ss;
	for (int i = 0; i < this->GetN(); i++)
	{
		for (int j = 0; j < this->GetN(); j++)
		{
			ss << m[i].v[j] << "  ";
		}
		ss << endl;
	}
	return ss.str();
}
ostream& operator << (ostream& out, const Matrix& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Matrix& A)
{
	for (int i = 0; i < A.GetN(); i++)
	{
		cout << "Enter  " << A.GetN() << " elements" << endl;
		for (int j = 0; j < A.GetN(); j++)
		{
			in >> A.m[i].v[j];
		}
		cout << endl;
	}
	return in;
}

void operator + (Matrix& A, Matrix& B)
{
	Matrix Value(A.GetN());

	for (int i = 0; i < A.GetN(); i++)
		for (int j = 0; j < B.GetN(); j++)
			Value[i][j] = A[i][j] + B[i][j];
	cout << Value;
}
bool operator == (Matrix& A, Matrix& B)
{
	int Counter = 0;

	for (int i = 0; i < A.GetN(); i++)
		for (int j = 0; j < A.GetN(); j++)
			if (A[i][j] == B[i][j])
				Counter++;
	return Counter == A.GetN() * A.GetN() ? true : false;
}

double Matrix::Norm()
{

	return abs(findMax() - findMin());
}
void Matrix::Comparison(Matrix& A, Matrix& B)
{
	if (A == B) cout << "Matrices are equal" << endl;
	else cout << "Matrices are not equal" << endl;
}

int Matrix::findMax()
{
	double Max = m[0][0];
	for (int i = 0; i < this->GetN(); i++)
	{
		for (int j = 0; j < this->GetN(); j++)
		{
			if (Max < m[i][j])
			{
				Max = m[i][j];
			}
		}
	}
	cout << Max << " Max" << endl;
	return Max;
}

int Matrix::findMin()
{
	double Min = m[0][0];
	for (int i = 0; i < this->GetN(); i++)
	{
		for (int j = 0; j < this->GetN(); j++)
		{
			if (Min > m[i][j])
			{
				Min = m[i][j];
			}
		}
	}
	cout << Min << " Min" << endl;
	return Min;
}


Matrix::~Matrix()
{
	for (int i = 0; i < N; i++)
		if (m[i].v != nullptr)
			delete[](m[i].v);

	if (m != nullptr)
		delete[] m;
}