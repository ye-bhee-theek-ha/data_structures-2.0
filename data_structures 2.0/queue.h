#pragma once
#include <cmath>
#include<iostream>


struct node
{
	int data;
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
		data = -1;
	}

	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


class queue
{
	node* array;
	int total_size;
	int head;
	int tail;

public:
	queue();
	bool is_empty();
	void increase_size();
	void push(node data);
	void pop();
	node front();
	~queue();
};

