#pragma once

#include <iostream>
#include "queue.h"

using namespace std;


class binary_search_tree
{
	node* root;

public:
	binary_search_tree();
	node* get_root();
	int get_data(node* root);
	void add(int data);
	void remove(int data);
	bool is_binary_tree();
	void print(int type);



	// utility functions
	int height(node* root);
	int depth(node* root);
	int min(node* root);

	void add_utility(node* root, int data);
	node* remove_utility(int data, node* root);
	bool is_binary_tree_utility(node* root, int min_limit, int max_limit);
	void print_utility(node* root, int type);
};


// another func: is_present to check if element is present and to check if present before removing a node
