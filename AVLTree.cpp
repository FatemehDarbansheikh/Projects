
#include<iostream>
using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;

	Node(int k)
	{
		key = k;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

class AVLTree
{
private:
	Node* root;

	int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

	int getHeight(Node* node)
	{
		if (node == nullptr)
			return 0;
		else
			return node->height;
	}
	
	int getBalance(Node* node)
	{
		if (node == nullptr)
			return 0;
		else
		{
			return getHeight(node->left);
			return getHeight(node->right);
		}
	}

	int getHeightValue(Node* node1,Node* node2)
	{
		int height1;
		if (node1 == nullptr)
			height1 = 0;
		else
			height1 = node1->height;

		int height2;
		if (node2 == nullptr)
			height2 = 0;
		else
			height2 = node2->height;

		if (height1 > height2)
			return height1;
		else
			return height2;
		
	}

	Node* rotateRight(Node* y)
	{
		Node* x = y->left;
		Node* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = 1 + getHeightValue(y->left, y->right);
		x->height = 1 + getHeightValue(x->left, x->right);

		return x;
	}

	Node* rotateLeft(Node* x)
	{
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = 1 + getHeightValue(x->left, x->right);
		y->height = 1 + getHeightValue(y->left, y->right);

		return y;
	}

	Node* Insert(Node* node, int key)
	{
		if (node == nullptr)
			return new Node(key);
		
		if (key < node->key)
			node->left = Insert(node->left, key);
		else if (key > node->key)
			node->right = Insert(node->right, key);
		else
			return node;

		node->height = 1 + getHeightValue(node->left, node->right);
		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key)
			return rotateRight(node);

		if (balance<-1 && key>node->right->key)
			return rotateLeft(node);

		if (balance > 1 && key > node->left->key)
		{
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		if (balance < -1 && key < node->right->key)
		{
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;

	}
Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
 
    return current; 
} 

	// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
Node* deleteNode(Node* root, int key) 
{ 
     
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 
 
    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
 
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
 
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            Node *temp = root->left ? 
                         root->left : 
                         root->right; 
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Node* temp = minValueNode(root->right); 
 
            // Copy the inorder successor's 
            // data to this node 
            root->key = temp->key; 
 
            // Delete the inorder successor 
            root->right = deleteNode(root->right, 
                                     temp->key); 
        } 
    } 
 
    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(getHeight(root->left), 
                           getHeight(root->right)); 
 
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root); 
 
    // If this node becomes unbalanced, 
    // then there are 4 cases 
 
    // Left Left Case 
    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rotateRight(root); 
 
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = rotateLeft(root->left); 
        return rotateRight(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return rotateLeft(root); 
 
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rotateRight(root->right); 
        return rotateLeft(root); 
    } 
 
    return root; 
} 
 
public:
	AVLTree()
	{
		root = nullptr;
	}

	void Insert(int key)
	{
		root = Insert(root, key);
	}
	
};

