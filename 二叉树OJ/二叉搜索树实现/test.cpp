#include "BST.hpp"

int main()
{
	BSTree<int> bst;
	bst.Insert(10);
	bst.Insert(9);
	bst.Insert(4);
	bst.Insert(8);
	bst.Insert(2);
	bst.Insert(19);
	bst.Insert(31);
	bst.Insert(7);
	
	bst.Inorder();
	cout << endl;
	bst.Root();

	cout << bst.Find(4)->_data << endl;

	bst.Erase(4);
	bst.Find(4);
	bst.Inorder();
	bst.Erase(10);
	bst.Root();
	bst.Inorder();
	return 0;
}