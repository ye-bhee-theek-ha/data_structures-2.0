#include "BST.h"

BST::BST()
{
	root = NULL;
}

node* BST::get_root()
{
	return root;
}

int BST::height(node* root)
{
	if (root == NULL)
		return 0;

	return (1 + max(height(root->right), height(root->left)));
}

int BST::depth(node* root)
{
	// return (height(this->root) - height(root));  
	// ^ => wrong: height func only gives height with respect to children not with respect to the whole tree
	//		only works to hive the whole height of tree

	if (root == NULL)
		return 0;

	return (1 + depth(root->parent));
}

void BST::add(node* root, int data)
{
	if (this->root == NULL)		// only for first node addition
	{
		this->root = new node(data);
		return;
	}
		
	// tree traversal
	node* temp;
	if (data <= root->data)
	{
		if (root->left != NULL)		// if subtree present then move to next
			add(root->left, data);
		else                        // if child is NULL then add node
		{
			temp = new node(data);
			root->left = temp;
			temp->parent = root;
		}
	}
	else
	{
		if (root->right != NULL)	// if subtree present then move to next
			add(root->right, data);
		else						// if child is NULL then add node
		{
			temp = new node(data);
			root->right = temp;
			temp->parent = root;
		}
	}
} 

void BST::add(int data)
{
	add(root, data);
}

void BST::print(node* root)
{
	if (this->root == NULL)
	{
		cout << "\n tree is empty.\n";
		return;
	}

	if (root == NULL)
		return;

	if (root != NULL)
		cout << " " << root->data << " ";
	else
		cout << " _ ";

	print(root->left);
	print(root->right);
}

void BST::print_A(node* root) // to be completed
{
	if (root == NULL)
	{
		return;
	}

	int len = depth(root);
	node* temp = root;

	for (int i = 0; i < len; i++)
	{
		if (root->parent != NULL && (root == root->parent->left || root == root->parent->right) && i == len - 1)
		{
			cout << "  #";
		}
		else
			cout << "  |";
	}
	
	cout << root->data << endl;

	print_A(root->right);
	print_A(root->left);
}
