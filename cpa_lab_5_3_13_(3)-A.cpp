#include <iostream>

using namespace std;

class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
	// cout << "+Node" << endl;
}

Node::~Node()
{
	// cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int& value);
	int size() const;
private:
	Node* head;
};

List::List()
	: head(nullptr)
{}

List::~List()
{
	while (head != nullptr)
	{
		Node* const new_head = head->next;
		delete head;
		head = new_head;
	}
}

void List::push_front(int value)
{
	Node* const new_head = new Node(value);
	new_head->next = head;
	head = new_head;
}

bool List::pop_front(int& value)
{
	if (!head)
		return false;
	Node* const new_head = head->next;
	value = head->value;
	delete head;
	head = new_head;
	return true;
}

int List::size() const
{
	int ret(0);
	for (Node* cur = head; cur != nullptr; cur = cur->next, ++ret);
	return ret;
}

int main()
{
	List list;
	for (int i = 0; i <= 5; ++i)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 0, val; i < 3; ++i)
	{
		int value;
		list.pop_front(val);
		cout << "popped " << val << ", size: " << list.size() << endl;
	}
	return 0;
}