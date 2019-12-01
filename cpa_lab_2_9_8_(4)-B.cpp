#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double arithmeticMean = 0.;
	double harmonicMean = 0.;
	double geometricMean = 1.;
	double rootMeanSquare = 0.;

	for (int i = 0; i < n; ++i)
	{
			arithmeticMean += vector[i];
			harmonicMean += 1. / vector[i];
			geometricMean *= vector[i];
			rootMeanSquare += vector[i] * vector[i];
	}
	arithmeticMean /= n;
	harmonicMean = n / harmonicMean;
	geometricMean = pow(geometricMean, 1. / n);
	rootMeanSquare = sqrt(rootMeanSquare / n);


	cout << "Arithmetic Mean = " << arithmeticMean << endl;
	cout << "Harmonic Mean   = " << harmonicMean << endl;
	cout << "Geometric Mean  = " << geometricMean << endl;
	cout << "RootMean Square = " << rootMeanSquare << endl;

	cout << endl;
	return 0;
}