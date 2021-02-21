#include <iostream>
#include "TreeNode.h"
int main()
{
	//test initilization
	TreeNode<int> testTree;

	//test insert -works
	testTree.insert(10);
	testTree.insert(5);
	testTree.insert(7);
	testTree.insert(15);
	testTree.insert(12);
	testTree.insert(17);
	testTree.insert(14);
	
	//test search-works
	std::cout << testTree.search(6) << std::endl;
	std::cout << testTree.search(1000) << std::endl;
	//test remove-works
	testTree.remove(14);
	std::cin;
	return 0;
}