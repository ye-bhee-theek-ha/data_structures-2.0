#include <iostream>

#include "Binary_Tree.h"
#include "BST.h"

using namespace std;

int main()
{
	/*Binary_Tree a;
	a.add(10);
	a.add(5);
	a.add(15);
	a.add(6);
	a.add(1);
	a.add(19);
	a.add(18);
	a.add(21);
	a.add(89);
	a.add(7);
	a.print();*/

	BST b;
	for (int i = 0; i < 5; i++)
	{
		b.add(i);
		b.print_A(b.get_root());
		cout << "\n\n -------------------------------------------- \n\n";
		b.add(i - 5);
		b.print_A(b.get_root());
		cout << "\n\n -------------------------------------------- \n\n";
		//cout << b.height(b.get_root()) << endl;
	}
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	b.add(2);
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	b.add(1);
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	b.add(0);
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	b.add(-7);
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	b.add(-10);
	b.print_A(b.get_root());
	cout << "\n\n -------------------------------------------- \n\n";
	
}