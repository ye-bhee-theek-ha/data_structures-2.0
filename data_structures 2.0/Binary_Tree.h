#pragma once

#include <iostream>

using namespace std;

// binary tree using dynamic arrays

class Binary_Tree
{
	int* array;
	int total_nodes;
	int capacity;
	int levels;

public:
	Binary_Tree();
	void add(int data);
	void increase_size();
	void remove(int data);
	void print();
	~Binary_Tree();
};

