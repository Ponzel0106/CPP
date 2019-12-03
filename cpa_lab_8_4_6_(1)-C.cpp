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
protected:
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

class InorderBST
	: public BST
{
public:
	friend ostream& operator<<(ostream& ostr, const InorderBST& bst);
};

class PreorderBST
	: public BST
{
public:
	void print(ostream& ostr) const
	{
		if (root)
			printHlp(ostr, root);
	}
	void printHlp(ostream& ostr, BSTNode* cur) const
	{
		ostr << cur->val << ' ';
		if (cur->left)
			printHlp(ostr, cur->left);
		if (cur->right)
			printHlp(ostr, cur->right);
	}

	friend ostream& operator<<(ostream& ostr, const PreorderBST& bst);
};

class PostorderBST
	: public BST
{
public:
	void print(ostream& ostr) const
	{
		if (root)
			printHlp(ostr, root);
	}
	void printHlp(ostream& ostr, BSTNode* cur)  const
	{
		if (cur->left)
			printHlp(ostr, cur->left);
		if (cur->right)
			printHlp(ostr, cur->right);
		ostr << cur->val << ' ';
	}

	friend ostream& operator<<(ostream& ostr, const PostorderBST& bst);
};

ostream& operator<<(ostream& ostr, const InorderBST& bst)
{
	// Recursive-less implementation

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
		ostr << cur->val << ' ';
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

ostream& operator<<(ostream& ostr, const PreorderBST& bst)
{
	bst.print(ostr);
	return ostr;
}

ostream& operator<<(ostream& ostr, const PostorderBST& bst)
{
	bst.print(ostr);
	return ostr;
}

int main(void)
{
	int n, val;
	cin >> n;
	PreorderBST preBST;
	InorderBST inBST;
	PostorderBST postBST;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		preBST.add(val);
		inBST.add(val);
		postBST.add(val);
	}
	cout << "Preorder: " << preBST << endl;
	cout << "Inorder: " << inBST << endl;
	cout << "Postorder: " << postBST << endl;
	return 0;
}