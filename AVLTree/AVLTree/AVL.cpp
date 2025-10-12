#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	int height;

	Node(int value)
	{
		data = value;
		left = right = NULL;
		height = 0;
	}
};

class AVL
{
private:
	Node* root;

	int max(int a, int b)
	{
		return (a > b ? a : b);
	}
	int getHeight(Node* n)
	{
		return (n == NULL ? -1 : n->height);
	}
	int getBalance(Node* n)
	{
		return getHeight(n->left) - getHeight(n->right);
	}
	Node* rightRotate(Node* y)
	{
		Node* x = y->left;
		Node* t = x->right;

		x->right = y;
		y->left = t;

		y->height = 1 + max(getHeight(y->left), getHeight(y->right));
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));

		return x;
	}
	Node* leftRotate(Node* x)
	{
		Node* y = x->right;
		Node* t = y->left;

		y->left = x;
		x->right = t;

		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(getHeight(y->left), getHeight(y->right));

		return y;
	}
	Node* insert(Node* r, int value)
	{
		if (r == NULL)
		{
			Node* newNode = new Node(value);
			r = newNode;
		}
		else if (value < r->data)
		{
			r->left = insert(r->left, value);
		}
		else if (value > r->data)
		{
			r->right = insert(r->right, value);
		}
		else
		{
			return r;
		}

		r->height = 1 + max(getHeight(r->left), getHeight(r->right));

		int b = getBalance(r);

		// LL
		if (b > 1 && value < r->left->data)
		{
			return rightRotate(r);
		}
		// RR
		if (b < -1 && value > r->right->data)
		{
			return leftRotate(r);
		}
		// LR
		if (b > 1 && value > r->left->data)
		{
			r->left = leftRotate(r->left);
			return rightRotate(r);
		}

		// RL
		if (b < -1 && value < r->right->data)
		{
			r->right = rightRotate(r->right);
			return leftRotate(r);
		}

		return r;
	}
	void preorder(Node* r)
	{
		if (r == NULL)
		{
			return;
		}

		cout << r->data << "\t";
		preorder(r->left);
		preorder(r->right);
	}
	void inorder(Node* r)
	{
		if (r == NULL)
		{
			return;
		}

		inorder(r->left);
		cout << r->data << "\t";
		inorder(r->right);
	}
	void postorder(Node* r)
	{
		if (r == NULL)
		{
			return;
		}

		postorder(r->left);
		postorder(r->right);
		cout << r->data << "\t";
	}
	Node* search(Node* r, int key)
	{
		if (r == NULL || r->data == key)
		{
			return r;
		}

		if (key < r->data)
			return search(r->left, key);
		else
			return search(r->right, key);
	}
	Node* findMin(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else if (r->left == NULL)
		{
			return r;
		}
		else
		{
			return findMin(r->left);
		}
	}
	Node* findMax(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else if (r->right == NULL)
		{
			return r;
		}
		else
		{
			return findMax(r->right);
		}
	}
	Node* remove(Node* r, int key)
	{
		if (r == NULL)
		{
			return NULL;
		}

		if (key < r->data)
		{
			r->left = remove(r->left, key);
		}
		else if (key > r->data)
		{
			r->right = remove(r->right, key);
		}
		else
		{
			if (r->left == NULL && r->right == NULL) // Leaf Node
			{
				r = NULL;
			}
			else if (r->left != NULL && r->right == NULL) //One Child On The Left
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL) //One Child On The Right
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else //Two Child On The Left and Right
			{
				Node* pre = findMax(r->left);
				r->data = pre->data;
				r->left = remove(r->left, pre->data);

				/*
				Node* succ = findMin(node->right);
				node->data = succ->data;
				node->right = remove(node->right, succ->data);
				*/
			}
		}

		r->height = 1 + max(getHeight(r->left), getHeight(r->right));

		int b = getBalance(r);


		// LL
		if (b > 1 && getBalance(r->left) >= 0)
		{
			return rightRotate(r);
		}
		// LR
		if (b > 1 && getBalance(r->left) < 0) 
		{
			r->left = leftRotate(r->left);
			return rightRotate(r);
		}

		// RR
		if (b < -1 && getBalance(r->right) <= 0)
		{
			return leftRotate(r);
		}
		// RL
		if (b < -1 && getBalance(r->right) > 0) 
		{
			r->right = rightRotate(r->right);
			return leftRotate(r);
		}


		return r;
	}



public:
	AVL()
	{
		root = NULL;
	}
	void insert(int item)
	{
		root = insert(root, item);
	}
	void inorder()
	{
		inorder(root);
		cout << endl;
	}
	void preorder()
	{
		preorder(root);
		cout << endl;
	}
	void postorder()
	{
		postorder(root);
		cout << endl;
	}
	bool search(int key)
	{
		return (search(root, key) != NULL);

		/*
		Node* result = Search(root, key);

		if (result == NULL)
			return false;
		else
			return true;
		*/
	}
	Node* findMin()
	{
		return findMin(root);
	}
	Node* findMax()
	{
		return findMax(root);
	}
	void remove(int key)
	{
		root = remove(root, key);
	}
};


int main()
{
	AVL tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);

	cout << "Inorder: ";
	tree.inorder();
	cout << "\n----------------------------------------------------------------------\n";

	cout << "Preorder: ";
	tree.preorder();
	cout << "\n----------------------------------------------------------------------\n";

	cout << "Postorder: ";
	tree.postorder();
	cout << "\n----------------------------------------------------------------------\n";

	cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found");
	cout << "\n----------------------------------------------------------------------\n";

	Node* min = tree.findMin();
	Node* max = tree.findMax();

	if (min)
		cout << "MiniNum = " << min->data;
	else
		cout << "MiniNUM = Not found";
	cout << "\n----------------------------------------------------------------------\n";

	if (max)
		cout << "MaxNum = " << max->data;
	else
		cout << "MaxNUM = Not found";
	cout << "\n----------------------------------------------------------------------\n";

	tree.remove(60);
	tree.remove(80);

	return 0;

	return 0;
}