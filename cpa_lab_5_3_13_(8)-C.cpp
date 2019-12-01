#include <iostream>

using namespace std;

class Node
{
public:
	Node(int val, Node* next = nullptr, Node* pr = nullptr);
	~Node();
	int value;
	Node* prev;
	Node* next;
};

Node::Node(int val, Node* next, Node* pr)
	: value(val), next(next), prev(pr)
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
		List(const List& rhs);
		~List();
		void push_front(int value);
		void push_back(int value);
		bool pop_front(int& value);
		bool pop_back(int& value);
		int  at(int index);
		void insert_at(int index, int value);
		void remove_at(int index);
		int size() const;
private:
	Node* head;
	Node* tail;
};

List::List()
	: head(nullptr), tail(nullptr)
{}

List::List(const List& rhs)
	: head(nullptr), tail(nullptr)
{
	Node* rhs_cur = rhs.head, *prev = nullptr;
	for (; rhs_cur != nullptr; rhs_cur = rhs_cur->next)
	{
		if (prev)
			prev = prev->next = tail = new Node(rhs_cur->value, nullptr, prev);
		else
			prev = head = tail = new Node(rhs_cur->value);
	}
}

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
	Node* const new_head = new Node(value, head);
	if (head == nullptr)
		tail = new_head;
	else
		head->prev = new_head;
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
	else
		head->prev = nullptr;
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
	Node* const new_tail = tail->prev;
	value = tail->value;
	delete tail;
	tail = new_tail;
	if (tail == nullptr)
		head = nullptr;
	else
		tail->next = nullptr;
	return true;
}

int List::at(int index)
{
	Node* cur = head;
	for (; index--; cur = cur->next);
	return cur->value;
}

void List::insert_at(int index, int value)
{
		if (index == 0)
		{
			push_front(value);
			return;
		}
		else if (index > size())
			return;
		Node* cur = head, * prev = nullptr;
		for (; index--; prev = cur, cur = cur->next);
		prev->next = new Node(value, cur);
		if (!cur)
			tail = prev->next;
}

void List::remove_at(int index)
{
	Node* cur = head, * prev = nullptr;
	for (; index--; prev = cur, cur = cur->next);
	if (prev)
		prev->next = cur->next;
	delete cur;
}

int List::size() const
{
	int ret(0);
	for (Node* cur = head; cur != nullptr; cur = cur->next, ++ret);
	return ret;
}

void printList(List& list)
{
	for (int i = 0; i < list.size(); i++)
		cout << "list[" << i << "] == " << list.at(i) << endl;
}

int main()
{
		List list1;
		list1.push_front(1);
		list1.push_front(2);
		list1.push_front(3);
		list1.push_front(4);
		cout << "list1" << endl;
		printList(list1);
		cout << endl;

		List list2(list1);
		cout << "list2" << endl;
		printList(list2);
		cout << endl;

		list1.insert_at(1, 6);
		list2.remove_at(2);

		cout << "list1" << endl;
		printList(list1);
		cout << endl << "list2" << endl;
		printList(list2);
		cout << endl;

		return 0;
}