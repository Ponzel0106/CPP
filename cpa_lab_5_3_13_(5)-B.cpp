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

Node::Node(int val)
	: value(val), next(nullptr)
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
	void push_back(int value);
	bool pop_front(int& value);
	bool pop_back(int& value);
	int size() const;
private:
	Node* head;
	Node* tail;
};

List::List()
	: head(nullptr), tail(nullptr)
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
	if (head == nullptr)
		tail = new_head;
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
	if (head == nullptr)
		tail = nullptr;
	return true;
}

void List::push_back(int value)
{
	Node* const new_tail = new Node(value);
	if (tail == nullptr)
		head = new_tail;
	else
		tail->next = new_tail;
	tail = new_tail;
}

bool List::pop_back(int& value)
{
	if (!tail)
		return false;
	else if (tail == head) // 1 element
	{
		value = head->value;
		delete head;
		head = tail = nullptr;
		return true;
	}
	Node* pre_tail = head;
	while (pre_tail->next != tail)
		pre_tail = pre_tail->next;
	pre_tail->next = nullptr;
	value = tail->value;
	delete tail;
	tail = pre_tail;
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
	
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);

	int value = 0;
	while (list.pop_back(value))
		cout << value << endl;
	return 0;
}