#include <iostream>

using namespace std;

int main(void)
{
	int matrix[10][10];

	for (int(*rowP)[10] = matrix, row = 0; row < 10; ++rowP, ++row)
		for (int* elemP = *rowP, col = 0; col < 10; ++elemP, ++col)
			*elemP = (row + 1) * (col + 1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
				cout.width(4);
				cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}