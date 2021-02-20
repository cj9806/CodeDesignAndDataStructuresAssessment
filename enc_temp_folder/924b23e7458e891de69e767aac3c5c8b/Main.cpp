#include <iostream>
#include "TreeNode.h"
int main()
{
	//test initilization
	TreeNode<int> testTree;

	//test insert -works
	testTree.insert(25);
	testTree.insert(10);
	testTree.insert(56);
	testTree.insert(30);
	testTree.insert(74);
	testTree.insert(15);
	testTree.insert(4);
	testTree.insert(29);
	testTree.insert(31);
	testTree.insert(6);
	//test search
	std::cout << testTree.search(6) << std::endl;
	std::cout << testTree.search(1000) << std::endl;
	//test remove
	testTree.remove(1000);
	testTree.remove(30);
	return 0;
}