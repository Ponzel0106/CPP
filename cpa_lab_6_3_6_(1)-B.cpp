#include <iostream>

using namespace std;

class Piece
{
public:
	virtual bool moveCorrect(int r1, int c1, int r2, int c2) const = 0;
};

class Man
	: public Piece
{
public:
	virtual bool moveCorrect(int r1, int c1, int r2, int c2) const override;
};

class King
	: public Piece
{
public:
	virtual bool moveCorrect(int r1, int c1, int r2, int c2) const override;
};


bool Man::moveCorrect(int r1, int c1, int r2, int c2) const
{
	return r2 == r1 + 1 && (c2 == c1 + 1 || c2 == c1 - 1);
}

bool King::moveCorrect(int r1, int c1, int r2, int c2) const
{
	return r2 - r1 == c2 - c1 || r2 - r1 == c1 - c2;
}


int main()
{
	Piece* pieces[2] = { new Man, new King };
	cout << "Call a method to check if Piece(Man) can be moved from b1 to c2: " << endl;
	cout << boolalpha << pieces[0]->moveCorrect(0, 1, 1, 2) << endl; // rows and columns are 0-based
	cout << "Call a method to check if Piece(King) can be moved from b1 to d3: " << endl;
	cout << boolalpha << pieces[1]->moveCorrect(0, 1, 2, 3) << endl;
	cout << "Call a method to check if Piece(Man) can be moved from b1 to d3: " << endl;
	cout << boolalpha << pieces[0]->moveCorrect(0, 1, 2, 3) << endl;
	for (int i = 0; i < 2; ++i)
		delete pieces[i];
	return 0;
}