#include <iostream>

using namespace std;

class Tree
{
public:
	virtual void draw() const = 0;
};

class Tree1
	: public Tree
{
public:
	virtual void draw() const;
};

class Tree2
	: public Tree
{
public:
	virtual void draw() const;
};

class Tree3
	: public Tree
{
public:
	virtual void draw() const;
};

void Tree1::draw() const
{
	cout << " /\\ " << endl;
	cout << "//\\\\" << endl;
}

void Tree2::draw() const
{
	cout << " /\\ " << endl;
	cout << "/**\\" << endl;
}

void Tree3::draw() const
{
	cout << " /\\ " << endl;
	cout << "/++\\" << endl;
}

int main()
{
		Tree* trees[3];
		trees[0] = new Tree1;
		trees[1] = new Tree2;
		trees[2] = new Tree3;
	for (int i = 0; i < 3; ++i)
	{
		cout << "Drawing " << i + 1 << ':' << endl;
		trees[i]->draw();
		delete trees[i];
	}
	return 0;
}
