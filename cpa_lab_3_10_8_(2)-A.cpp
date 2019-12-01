#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection
{
	int  elno;
	int* elements;
};

void AddToCollection(Collection& col, int element)
{
	if (col.elno == 0)
		col.elements = new int[++col.elno]{ element };
	else
	{
		int* newStorage = new int[col.elno + 1];
		for (int i = 0; i < col.elno; ++i)
			newStorage[i] = col.elements[i];
		newStorage[col.elno] = element;
		delete[] col.elements;
		col.elements = newStorage;
		++col.elno;
	}
}

void PrintCollection(Collection col)
{
		cout << "[ ";
		for (int i = 0; i < col.elno; ++i)
			cout << col.elements[i] << " ";
		cout << "]" << endl;
}

int main(void)
{
	Collection collection = { 0, nullptr };

	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	for (int i = 0; i < elems; ++i)
		AddToCollection(collection, rand() % 100 + 1);
	PrintCollection(collection);
	delete[] collection.elements;
	return 0;
}