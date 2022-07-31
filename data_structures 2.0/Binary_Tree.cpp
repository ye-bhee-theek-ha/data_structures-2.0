#include <cmath>
#include "Binary_Tree.h"

Binary_Tree::Binary_Tree()
{
	array = new int[1];
	total_nodes = 0;
	capacity = 1;
	levels = 1;

	for (int i = 0; i < capacity; i++) // initializing all nodes to -1
	{
		array[i] = -1;
	}
}

void Binary_Tree::add(int data)
{
	int current_node = 0;

	while (array[current_node] != -1)
	{
		if (data > array[current_node])
		{
			current_node = ((2 * current_node) + 2); // right child
		}
		else
		{
			current_node = ((2 * current_node) + 1); // left child
		}

		if (current_node >= capacity)
		{
			increase_size();
		}
	}

	total_nodes++;
	array[current_node] = data;
}

void Binary_Tree::increase_size()
{
	cout << "\n size increased \n";

	int* temp = new int[capacity];
	int cap = capacity;

	for (int i = 0; i < capacity; i++)
	{
		temp[i] = array[i];
	}

	capacity = pow(2, levels) + capacity;
	levels++;
	array = new int[capacity];

	for (int i = 0; i < capacity; i++)
	{
		array[i] = -1;
	}

	for (int i = 0; i < cap; i++)
	{
		array[i] = temp[i];
	}

	cout << capacity << "\n";

	delete[] temp;
}


void Binary_Tree::remove(int data)
{
	//int current_node = 0;
	//int current_level = 0;

	//// finding phase	

	//while ((array[current_node] != -1) && (current_level < levels))
	//{
	//	if (data == array[current_node])
	//	{
	//		break;
	//	}
	//	else if (data < array[current_node])
	//	{
	//		current_node = (2 * current_node) + 1;	// left
	//	}
	//	else if (data > array[current_node])
	//	{
	//		current_node = (2 * current_node) + 2;	// right
	//	}
	//}


	//// deleting phase
	//int left = array[(2 * current_node) + 1];
	//int right = array[(2 * current_node) + 2];
	//int parent = 0;

	//// case 1
	//if (right > capacity) // if next child node out of range then it is the last node (leaf)
	//{
	//	array[current_node] = -1;
	//}
	//else if ((array[right] == -1) && (array[left] == -1)) // if both child nodes are empty (leaf)
	//{
	//	array[current_node] = -1;
	//}
	//// case 2
	//else if ((array[right] == -1 && (array[left] != -1))) // right node is empty => move left subtree up
	//{
	//	while (array[left] != -1 || array[right] != -1)
	//	{
	//		if (array[left] == -1)
	//		{
	//			array[current_node] = array[right];
	//			current_node = right;
	//		}
	//		else if (array[right] == -1)
	//		{
	//			array[current_node] = array[left];
	//			current_node = left;
	//		}
	//		else
	//		{

	//		}

	//		left = array[(2 * current_node) + 1];
	//		right = array[(2 * current_node) + 2];


	//	}
	//	

	//	
	//}



}

void Binary_Tree::print()
{
	cout << endl;
	int counter = 0;
	for (int i = 0; i < levels; i++)
	{
		for (int j = pow(2, levels) - pow(2, i); j > 0; j--)
		{
			cout << "  ";
		}
		for (int j = 0; j < pow(2, i); j++ ,counter++)
		{
			cout << " " << array[counter] << " ";
		}
		cout << endl<<endl;
	}
	cout << endl << endl;

	counter = 0;

	cout << endl;

	cout << array[counter];

	print_child(counter, 1);

}

void Binary_Tree::print_child(int current, int count)
{
	int left = (2 * current) + 1;
	int right = (2 * current) + 2;

	if (array[right] == -1 || right > capacity)
	{

		return;
	}

	cout << "\n |";
	for (int i = 0; i < count; i++)
	{
		cout << "---";
	}

	cout << "|- " << array[right];
	print_child(right, count+1);


	if (array[left] == -1 || left > capacity)
	{
		return;
	}

	cout << "\n |";
	for (int i = 0; i < count; i++)
	{
		cout << "---";
	}

	cout << "|- " << array[left];
	print_child(left, count+1);
}


Binary_Tree::~Binary_Tree()
{
	cout << "\n\n destructor called \n";
	delete[] array;
}
