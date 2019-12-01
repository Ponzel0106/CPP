#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	int maxball;
	int ballsno;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;

	if (ballsno > maxball)
	{
		cout << "Balls number should be less than max ball number!" << endl;
		return 0;
	}

	srand(time(NULL));

	int* balls = new int[ballsno];
	for (int i = 0; i < ballsno; ++i)
	{
		bool newBall;
		do
		{
			balls[i] = (rand() % maxball) + 1;
			newBall = true;
			for (int j = 0; j < i; ++j)
				if (balls[j] == balls[i])
					newBall = false;
		} while (!newBall);
	}

	for (int i = 0; i < ballsno; ++i)
		cout << balls[i] << ' ';
	cout << endl;

	delete[] balls;
	return 0;
}