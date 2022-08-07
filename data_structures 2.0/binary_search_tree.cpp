#include "binary_search_tree.h"

queue tree;  // queue can also be made for int

binary_search_tree::binary_search_tree()
{
	root = NULL;
}

node* binary_search_tree::get_root()
{
	if (root == NULL)
		cout << "\n empty tree\n";
	else
		return root;
}

int binary_search_tree::get_data(node* root)
{
	if (root == NULL)
		cout << "\n empty node. \n";
	else
		return root->data;
}

void binary_search_tree::add(int data)
{
	add_utility(root, data);
}

void binary_search_tree::remove(int data)
{
	remove_utility(data, root);
}

bool binary_search_tree::is_binary_tree()
{
	return is_binary_tree_utility(root, INT_MIN, INT_MAX);
}

void binary_search_tree::print(int type)
{
	print_utility(root, type);
}



// utility functions

int binary_search_tree::height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int height_left = height(root->left);
	int height_right = height(root->right);

	return (1 + max(height_left, height_right));
}

int binary_search_tree::depth(node* root)
{
	node* temp = this->root;
	int counter = 0;

	while (temp != root)
	{
		if (temp == NULL)
		{
			cout << "\n depth func(): node not present\n";
			return -1;
		}

		if (root->data > temp->data)
			temp = temp->right;
		else
			temp = temp->left;

		counter++;
	}
	return counter;
}

int binary_search_tree::min(node* root)
{
	if (root->left == NULL)
		return root->data;
	
	min(root->left);
}

void binary_search_tree::add_utility(node* root, int data)
{

	if (this->root == NULL)		//only for first node
	{
		this->root = new node(data);
		return;
	}

	if (data <= root->data)
	{
		if (root->left != NULL)
			add_utility(root->left, data);
		else
			root->left = new node(data);
	}
	else
	{
		if (root->right != NULL)
			add_utility(root->right, data);
		else
			root->right = new node(data);
	}
}

node* binary_search_tree::remove_utility(int data, node* root)
{
	if (root == NULL)
		return root;

	else if (data < root->data)
	{
		if (root->left->data == data) // if next LEFT node is the one to delete
			root->left = remove_utility(data, root->left);
		else
			remove_utility(data, root->left);
	}

	else if (data > root->data)
	{
		if (root->right->data == data) // // if next RIGHT node is the one to delete
			root->right = remove_utility(data, root->right);
		else
			remove_utility(data, root->right);
	}

	else if (data == root->data)
	{
		if (root->left == NULL && root->right == NULL) // 1st case : leaf node
		{
			delete[] root;
			root = NULL;
		}
		else if (root->right == NULL) // 2nd case : one child
		{
			node* temp = root;
			root = root->left;
			delete[] temp;
		}
		else if (root->left == NULL) // 2 childs
		{
			node* temp = root;
			root = root->right;
			delete[] temp;
		}
		else // 3rd case
		{
			int minimum = min(root->right);
			root->data = minimum;
			root->right = remove_utility(minimum, root->right);
		}
		return root;
	}
		

}

bool binary_search_tree::is_binary_tree_utility(node* root, int min_limit, int max_limit)
{
	if (root == NULL)
		return true;

	if (root->data >= min_limit && root->data < max_limit)
	{
		if (is_binary_tree_utility(root->left, min_limit, root->data) && is_binary_tree_utility(root->right, root->data, max_limit))
		{
			return true;
		}
		return false;
	}
}

void binary_search_tree::print_utility(node* root, int type)
{
	if (root == NULL)
	{
		if (this->root == NULL)
		{
			cout << "\n empty tree\n";
		}
		return;
	}

	if (type == 0) // breadth first
	{
		tree.push(*root);
		
		while (!tree.is_empty())
		{
			if (tree.front().left != NULL)
				tree.push(*(tree.front().left));

			if (tree.front().right != NULL)
				tree.push(*(tree.front().right));

			cout << (tree.front().data) << " ";
			tree.pop();
		}
	}
	
	else if (type == 1) // preorder traversal
	{
		for (int i = 0; i < depth(root); i++)
		{
			cout << "||-";
		}
		cout << root->data << "\n";

		print_utility(root->left, type);
		print_utility(root->right, type);
	}

	else if (type == 2) // inorder traversal
	{
		print_utility(root->left, type);

		for (int i = 0; i < depth(root); i++)
		{
			cout << "||-";
		}
		cout << root->data << "\n";

		print_utility(root->right, type);
	}

	else if (type == 3) // postorder traversal
	{
		print_utility(root->left, type);

		print_utility(root->right, type);

		for (int i = 0; i < depth(root); i++)
		{
			cout << "||-";
		}
		cout << root->data << "\n";
	}
	
}
