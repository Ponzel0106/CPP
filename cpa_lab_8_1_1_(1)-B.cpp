#include <iostream>

using namespace std;

class Matrix
{
public:
		friend istream& operator>>(istream& istr, Matrix& m);
		friend ostream& operator<<(ostream& ostr, const Matrix& m);
private:
		int data[2][2] = {};
};

istream& operator>>(istream& istr, Matrix& m)
{
		for (size_t i = 0; i < 2; ++i)
			for (size_t j = 0; j < 2; ++j)
				istr >> m.data[i][j];
		return istr;
}

ostream& operator<<(ostream& ostr, const Matrix& m)
{
		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = 0; j < 2; ++j)
				ostr << m.data[i][j] << ' ';
			ostr << endl;
		}
		return ostr;
}

int main(void)
{
		Matrix m;
		cin >> m;
		cout << m << endl;
		return 0;
}