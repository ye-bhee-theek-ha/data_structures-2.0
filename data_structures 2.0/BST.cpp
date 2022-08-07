//#include "BST.h"
//
//BST::BST()
//{
//	root = NULL;
//}
//
//node* BST::get_root()
//{
//	return root;
//}
//
//int BST::height(node* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return (1 + max(height(root->right), height(root->left)));
//}
//
//int BST::depth(node* root)
//{
//	// return (height(this->root) - height(root));  
//	// ^ => wrong: height func only gives height with respect to children not with respect to the whole tree
//	//		only works to hive the whole height of tree
//
//	if (root == NULL)
//		return 0;
//
//	return (1 + depth(root->parent));
//}
//
//int BST::pos(node* root)
//{
//	// 0 for NULL, -1 if left, 1 if right
//
//	if (root == NULL || root->parent == NULL)
//		return 0;
//	
//	if (root->data > root->parent->data)
//		return 1;
//
//	if (root->data <= root->parent->data)
//		return -1;
//}
//
//void BST::swap(node* A, node* B)
//{
//
//}
//
//void BST::add(node* root, int data)
//{
//	if (this->root == NULL)		// only for first node addition
//	{
//		this->root = new node(data);
//		return;
//	}
//		
//	// tree traversal
//	node* temp;
//	if (data <= root->data)
//	{
//		if (root->left != NULL)		// if subtree present then move to next
//			add(root->left, data);
//		else                        // if child is NULL then add node
//		{
//			temp = new node(data);
//			root->left = temp;
//			temp->parent = root;
//		}
//	}
//	else
//	{
//		if (root->right != NULL)	// if subtree present then move to next
//			add(root->right, data);
//		else						// if child is NULL then add node
//		{
//			temp = new node(data);
//			root->right = temp;
//			temp->parent = root;
//		}
//	}
//} 
//
//void BST::add(int data)
//{
//	add(root, data);
//}
//
//void BST::remove(int data)
//{
//	remove(root, data);
//}
//
//void BST::remove(node* root, int data)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	node* temp = root;
//
//	if (root->data == data)
//	{
//		if (root->left == NULL && root->right == NULL)
//		{
//			if (pos(root) == 0)
//			{
//				delete[] root;
//			}
//			else if (pos(root) == -1)
//			{
//				root->parent->left = NULL;
//				delete[] root;
//			}
//			else if (pos(root) == 1)
//			{
//				root->parent->right = NULL;
//				delete[] root;
//			}
//		}
//		else if (root->left != NULL && root->right == NULL) // if LEFT subtree
//		{
//			if (pos(root) == 0) // first node
//			{
//				this->root = root->left;
//				delete[] root;
//			}
//			else if (pos(root) == 1) // if root is a right child
//			{
//				temp->parent->right = temp->left;
//				temp->left->parent = temp->parent;
//				delete[] temp;
//			}
//			else if (pos(root) == -1) // if root is a left child
//			{
//				temp->parent->left = temp->left;
//				temp->left->parent = temp->parent;
//				delete[] temp;
//			}
//		}
//		else if (root->left == NULL && root->right != NULL) // if RIGHT subtree
//		{
//			if (pos(root) == 0) // first node
//			{
//				this->root = root->left;
//				delete[] root;
//			}
//			else if (pos(root) == 1) // if root is a right child
//			{
//				temp->parent->right = temp->right;
//				temp->right->parent = temp->parent;
//				delete[] temp;
//			}
//			else if (pos(root) == -1) // if root is a left child
//			{
//				temp->parent->left = temp->right;
//				temp->right->parent = temp->parent;
//				delete[] temp;
//			}
//		}
//		// not best approch
//		else if (root->left != NULL && root->right != NULL) // if both subtree
//		{
//			temp = root->left;
//
//			while (temp->right != NULL) // finding the largest in the left subtree
//			{
//				temp = temp->right;
//			}
//			int temp2 = root->data;
//
//			// swapping places of node to be deleted and largest node in left subtree
//			root->data = temp->data; 
//			temp->data = temp2;
//
//			remove(root->left, data);
//		}
//
//		return;
//	}
//
//	if (data <= root->data)
//		remove(root->left, data);
//
//	if (data > root->data)
//		remove(root->right, data);
//}
//
//void BST::print(node* root)
//{
//	if (this->root == NULL)
//	{
//		cout << "\n tree is empty.\n";
//		return;
//	}
//
//	if (root == NULL)
//		return;
//
//	if (root != NULL)
//		cout << " " << root->data << " ";
//	else
//		cout << " _ ";
//
//	print(root->left);
//	print(root->right);
//}
//
//void BST::print_A(node* root) // to be completed
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	int len = depth(root);
//	node* temp = root;
//
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//		{
//			cout << "  #";
//		}
//		else
//			cout << "  |";
//	}
//	
//	cout << root->data << endl;
//
//	print_A(root->right);
//	print_A(root->left);
//}
