#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct BSTNode
{
	BSTNode(int val, BSTNode* left = nullptr, BSTNode* right = nullptr)
		: val(val), left(left), right(right)
	{}
	int val;
	BSTNode* left;
	BSTNode* right;
};

class BST
{
public:
	~BST()
	{
		clear(root);
		root = nullptr;
	}

	void add(int val)
	{
		if (!root)
		{
			root = new BSTNode(val);
			return;
		}
		BSTNode* cur = root;
		while (true)
			if (val < cur->val)
			{
				if (cur->left)
					cur = cur->left;
				else
				{
					cur->left = new BSTNode(val);
					break;
				}
			}
			else if (val > cur->val)
			{
				if (cur->right)
					cur = cur->right;
				else
				{
					cur->right = new BSTNode(val);
					break;
				}
			}
			else
				break;
	}

	friend ostream& operator<<(ostream& ostr, const BST& bst);
private:
	void clear(BSTNode* node)
	{
		if (node->left)
			clear(node->left);
		if (node->right)
			clear(node->right);
		delete node;
	}

	BSTNode* root = nullptr;
};

ostream& operator<<(ostream& ostr, const BST& bst)
{
	bool curFromUp = false;
	BSTNode* cur = bst.root;
	if (cur == nullptr)
		return ostr;

	stack<BSTNode*> up;
	while (true)
	{
		if (!curFromUp && cur->left)
		{
			up.push(cur);
			cur = cur->left;
			// curFromUp = false; // already false
			continue;
		}
		ostr << cur->val << endl;
		if (cur->right)
		{
			cur = cur->right;
			curFromUp = false;
			continue;
		}
		if (up.empty())
			break;
		cur = up.top();
		up.pop();
		curFromUp = true;
	}

	return ostr;
}

int main(void)
{
	int n, val;
	cin >> n;
	BST bst;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		bst.add(val);
	}
	cout << bst;
	return 0;
}