#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
	int top() const
	{
		checkEmpty();
		return data.back();
	}
	void pop()
	{
		checkEmpty();
		data.pop_back();
	}
	void push(int val)
	{
		data.push_back(val);
	}

	// Operator for inserting and reading THE TOP OF THE STACK
	friend istream& operator>>(istream& istr, Stack& s);
	friend ostream& operator<<(ostream& ostr, const Stack& s);
private:
	void checkEmpty() const
	{
		if (data.empty())
			throw exception("Stack is empty.");
	}

	vector<int> data;
};

istream& operator>>(istream& istr, Stack& s)
{
	int elem;
	istr >> elem;
	s.push(elem);
	return istr;
}

ostream& operator<<(ostream& ostr, const Stack& s)
{
	int elem;
	ostr << s.top() << endl;
	return ostr;
}

int main(void)
{
	size_t n, cur, remCnt;
	cin >> n;
	Stack st;
	for (size_t i = 0; i < n; ++i)
		cin >> st;
	cin >> remCnt;
	try
	{
		while (remCnt--)
		{
			cout << st;
			st.pop();
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	return 0;
}