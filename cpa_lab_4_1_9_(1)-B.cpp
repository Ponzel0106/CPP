#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int c;
	cin >> c;
	int* n = new int[c], **g = new int* [c];
	for (int i = 0; i < c; ++i)
	{
		cin >> n[i];
		g[i] = new int[n[i]];
		for (int j = 0; j < n[i]; ++j)
			cin >> g[i][j];
	}

	cout << fixed << setprecision(2);
	float ov_fin = 0.f;
	for (int i = 0; i < c; ++i)
	{
		float fin = 0.f;
		for (int j = 0; j < n[i]; ++j)
			fin += g[i][j];
		fin /= n[i];
		ov_fin += fin;
		cout << "Course " << i << ": final " << fin << ", grades: ";
		for (int j = 0; j < n[i]; ++j)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	ov_fin /= c;
	cout << "Overall final " << ov_fin << endl;

	for (int i = 0; i < c; ++i)
		delete[] g[i];
	delete[] n;
	delete[] g;
	return 0;
}