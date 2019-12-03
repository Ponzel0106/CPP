#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix(size_t n = 0, size_t m = 0)
		: data(n, vector<int>(m))
	{}

	size_t rows() const
	{
		return data.size();
	}
	size_t cols() const
	{
		if (rows() == 0) // empty
			return 0;
		return data[0].size();
	}
	// Access operators
	vector<int>& operator[](size_t i)
	{
		return data[i];
	}
	const vector<int>& operator[](size_t i) const
	{
		return data[i];
	}
	// Arithmetic operators
	Matrix operator+(int rhs) const
	{
		Matrix ret(*this);
		for (auto& row : ret.data)
			for (auto& elem : row)
				elem += rhs;
		return ret;
	}
	Matrix operator+(const Matrix& rhs) const
	{
		if (rows() != rhs.rows())
			throw std::invalid_argument(
				"Incompatible matrix sizes for addition");
		Matrix ret(*this);
		for (size_t i = 0; i < data.size(); ++i)
			for (size_t j = 0; j < data[0].size(); ++j)
				ret[i][j] += rhs[i][j];
		return ret;
	}
	Matrix operator-(int rhs) const
	{
		Matrix ret(*this);
		for (auto& row : ret.data)
			for (auto& elem : row)
				elem -= rhs;
		return ret;
	}
	Matrix operator-(const Matrix& rhs) const
	{
		if (rows() != rhs.rows())
			throw std::invalid_argument(
				"Incompatible matrix sizes for subtraction");
		Matrix ret(*this);
		for (size_t i = 0; i < data.size(); ++i)
			for (size_t j = 0; j < data[0].size(); ++j)
				ret[i][j] -= rhs[i][j];
		return ret;
	}
	Matrix operator*(int rhs) const
	{
		Matrix ret(*this);
		for (auto& row : ret.data)
			for (auto& elem : row)
				elem *= rhs;
		return ret;
	}
	Matrix operator*(const Matrix& rhs) const
	{
		if (rows() == 0 || rhs.rows() == 0)
			throw std::invalid_argument(
				"Can't multiply empty matrices");
		if (cols() != rhs.rows())
			throw std::invalid_argument(
				"Incompatible matrix sizes for multiplication");
		Matrix ret(rows(), rhs.cols());
		for (size_t i = 0; i < ret.rows(); ++i)
			for (size_t j = 0; j < ret.cols(); ++j)
			{
				ret[i][j] = 0; // for clarity, because it should already be zero
				for (size_t k = 0; k < rhs.rows(); ++k)
					ret[i][j] += data[i][k] * rhs[k][j];
			}
		return ret;
	}
	// Stream operators
	friend ostream& operator<<(ostream& ostr, const Matrix& mat)
	{
		for (size_t i = 0; i < mat.rows(); ++i)
		{
			for (size_t j = 0; j < mat.cols(); ++j)
				cout << mat[i][j] << ' ';
			cout << endl;
		}
		return ostr;
	}
private:
	vector<vector<int>> data;
};

int main(void)
{
	size_t n, m, t;
	Matrix mats[2];
	for (size_t k = 0; k < 2; ++k)
	{
		cout << "Enter matrix " << k << " sizes and elements: ";
		cin >> n >> m;
		mats[k] = Matrix(n, m);
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				cin >> mats[k][i][j];
	}
	cout << "Enter number to test with them (t): ";
	cin >> t;

	cout << "Matrix 0 + t: " << endl << mats[0] + t << endl;
	cout << "Matrix 0 - t: " << endl << mats[0] - t << endl;
	cout << "Matrix 0 * t: " << endl << mats[0] * t << endl;
	try {
		cout << "Matrix 0 + Matrix 1: " << endl << mats[0] + mats[1] << endl;
	} catch (const exception & ex) {
		cout << "Exception: " << ex.what() << endl;
	}
	try {
		cout << "Matrix 0 - Matrix 1: " << endl << mats[0] - mats[1] << endl;
	} catch (const exception & ex) {
		cout << "Exception: " << ex.what() << endl;
	}
	try {
			cout << "Matrix 0 * Matrix 1: " << endl << mats[0] * mats[1] << endl;
		} catch (const exception & ex) {
			cout << "Exception: " << ex.what() << endl;
		}

	return 0;
}