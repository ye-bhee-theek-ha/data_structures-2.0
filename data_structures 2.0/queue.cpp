#include "queue.h"

queue::queue()
{
	array = new node();
	total_size = 1;
	head = -1;
	tail = -1;
}


void queue::increase_size()
{
	//std::cout << "\n size increased \n";
	node* temp = new node[total_size];
	int new_size = pow(2, total_size);

	for (int i = 0; i < total_size; i++)
	{
		temp[i] = array[i];
	}

	array = new node[new_size];

	for (int i = 0; i < total_size; i++)
	{
		array[i] = temp[i];
	}

	total_size = new_size;
	delete[] temp;
}


void queue::push(node data)
{
	if (is_empty())
	{
		head = 0;
		tail = 0;
		array[head] = data;
	}
	else
	{
		if ((tail + 1) % total_size == head)
		{
			increase_size();
		}

		tail = (tail + 1) % total_size;
		array[tail] = data;
	}
}


bool queue::is_empty()
{
	if (head == -1 || tail == -1)
		return true;

	return false;
}

void queue::pop()
{
	if (head == tail)
	{
		array[head] = NULL;
		head = -1;
		tail = -1;
	}
	else if (!is_empty())
	{
		array[head] = NULL;
		head = (head + 1) % total_size;
	}
	else
	{
		//std::cout << "\n queue is empty\n";
	}
}

node queue::front()
{
	if (!is_empty())
		return array[head];

		//std::cout << "front : queue empty";
}

queue::~queue()
{
	delete[] array;
}



