#include <iostream>
using namespace std;

enum Color
{
	RED, BLACK
};

class Node
{
public:
	int key;
	Color color;
	Node *parent;
	Node *left;
	Node *right;

	Node(int k, Color c)
	{
		key = k;
		color = c;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

class RedBlackTree
{
private:
	Node *root;
	Node *nullNode;

	void leftRotate(Node *x)
	{
		Node *y = x->right;
		x->right = y->left;
		if (y->left != nullNode)
			y->left->parent = x;

		y->parent = x->parent;
		if (x->parent == nullNode)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void rightRotate(Node *y)
	{
		Node *x = y->left;
		y->left = x->right;
		if (x->right != nullNode)
			x->right->parent = y;

		x->parent = y->parent;
		if (y->parent == nullNode)
			root = x;
		else if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;

		x->right = y;
		y->parent = x;
	}

	void fixInsert(Node *z)
	{
		while (z->parent->color == RED)
		{
			if (z->parent == z->parent->parent->left)
			{
				Node *y = z->parent->parent->right;
				if (y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->right)
					{
						z = z->parent;
						leftRotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rightRotate(z->parent->parent);
				}
			}
			else
			{
				Node *y = z->parent->parent->left;
				if (y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->left)
					{
						z = z->parent;
						rightRotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					leftRotate(z->parent->parent);
				}
			}
		}
		root->color = BLACK;
	}

	void transplant(Node *u, Node *v)
	{
		if (u->parent == nullNode)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;

		v->parent = u->parent;
	}

	Node *findSuccessor(Node *node)
	{
		Node *successor = node->right;
		while (successor->left != nullNode)
			successor = successor->left;
		return successor;
	}

	void fixRemove(Node *x)
	{
		while (x != root && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				Node *w = x->parent->right;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					w = x->parent->right;
				}
				if (w->left->color == BLACK && w->right->color == BLACK)
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						rightRotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					leftRotate(x->parent);
					x = root;
				}
			}
			else
			{
				Node *w = x->parent->left;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					w = x->parent->left;
				}
				if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						leftRotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = BLACK;
	}

public:
	RedBlackTree()
	{
		nullNode = new Node(0, BLACK);
		root = nullNode;
	}

	void Insert(int key)
	{
		Node *z = new Node(key, RED);
		Node *y = nullNode;
		Node *x = root;

		while (x != nullNode)
		{
			y = x;
			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}

		z->parent = y;
		if (y == nullNode)
			root = z;
		else if (z->key < y->key)
			y->left = z;
		else
			y->right = z;

		fixInsert(z);
	}

	void Remove(int key)
	{
		Node *z = root;
		while (z != nullNode)
		{
			if (key == z->key)
			{
				Node *y = z;
				Color yOriginalColor = y->color;
				Node *x;

				if (z->left == nullNode)
				{
					x = z->right;
					transplant(z, z->right);
				}
				else if (z->right == nullNode)
				{
					x = z->left;
					transplant(z, z->left);
				}
				else
				{
					y = findSuccessor(z);
					yOriginalColor = y->color;
					x = y->right;

					if (y->parent == z)
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}

				if (yOriginalColor == BLACK)
					fixRemove(x);

				delete z;
				break;
			}
			else if (key < z->key)
				z = z->left;

			else
				z = z->right;
		}
	}
};
