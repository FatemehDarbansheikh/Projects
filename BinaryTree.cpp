#include <iostream>
#include <queue>
using namespace std;

class TreeNode 
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) 
	{
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree 
{
private:
	TreeNode* root;

	TreeNode* create(int values[], int start, int end) 
	{
		if (start > end)
			return nullptr;
		
		int mid = (start + end) / 2;
		TreeNode* newNode = new TreeNode(values[mid]);

		newNode->left = create(values, start, mid - 1);
		newNode->right = create(values, mid + 1, end);

		return newNode;
	}

	int height(TreeNode* node) 
	{
		if (node == nullptr)
			return 0;
		
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);

		return 1 + max(leftHeight, rightHeight);
	}

	int countLeaves(TreeNode* node) 
	{
		if (node == nullptr)
			return 0;
		
		if (node->left == nullptr && node->right == nullptr)
			return 1;
		
		return countLeaves(node->left) + countLeaves(node->right);
	}

	int countNodes(TreeNode* node) 
	{
		if (node == nullptr)
			return 0;
		
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

	TreeNode* findMaxNode(TreeNode* node) 
	{
		while (node->right != nullptr)
			node = node->right;
		
		return node;
	}

	bool isComplete(TreeNode* node, int index, int count) 
	{
		if (node == nullptr)
			return true;

		if (index >= count)
			return false;
		
		return isComplete(node->left, 2 * index + 1, count) &&
			isComplete(node->right, 2 * index + 2, count);
	}

	
	void reverseTree(TreeNode* node) 
	{
		if (node == nullptr)
			return;
		
		TreeNode* temp = node->left;
		node->left = node->right;
		node->right = temp;

		reverseTree(node->left);
		reverseTree(node->right);
	}

	void inorder(TreeNode* node) 
	{
		if (node != nullptr) 
		{
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

	void postorder(TreeNode* node) 
	{
		if (node != nullptr) 
		{
			postorder(node->left);
			postorder(node->right);
			cout << node->data << " ";
		}
	}

	void preorder(TreeNode* node) 
	{
		if (node != nullptr) 
		{
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

public:
	BinaryTree() 
	{
		root = nullptr;
	}

	void createR(int values[], int size) 
	{
		root = create(values, 0, size - 1);
	}

	int heightR() 
	{
		return height(root);
	}

	int countLeavesR() 
	{
		return countLeaves(root);
	}

	int countNodesR() 
	{
		return countNodes(root);
	}

	void deleteTreeR();
		


	int findMaxR()
	{
		TreeNode* maxNode = findMaxNode(root);
		if (maxNode != nullptr)
			return maxNode->data;
		else
			return -1;
	}

	bool isCompleteR() 
	{
		int nodeCount = countNodesR();
		return isComplete(root, 0, nodeCount);
	}

	void reverseTreeR() 
	{
		reverseTree(root);
	}

	void inorderR() 
	{
		inorder(root);
		cout << endl;
	}

	void postorderR() 
	{
		postorder(root);
		cout << endl;
	}

	void preorderR() 
	{
		preorder(root);
		cout << endl;
	}
};

