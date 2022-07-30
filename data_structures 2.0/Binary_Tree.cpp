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

	for (int i = 0; i < total_nodes; i++)
	{
		array[i] = temp[i];
	}

	cout << capacity << "\n";

	print();

	delete[] temp;
}


void Binary_Tree::remove(int data)
{

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
		cout << endl;
	}
	cout << endl;
}

Binary_Tree::~Binary_Tree()
{
	cout << "\n\n destructor called \n";
	delete[] array;
}
