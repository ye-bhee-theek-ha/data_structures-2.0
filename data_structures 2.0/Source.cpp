#include <iostream>

#include "Binary_Tree.h";

using namespace std;

int main()
{
	Binary_Tree a;
	
	for (int i = 0; i < 10; i++)
	{
		a.add(i);
		a.print();
	}
	a.add(10);
	a.print();
	
}