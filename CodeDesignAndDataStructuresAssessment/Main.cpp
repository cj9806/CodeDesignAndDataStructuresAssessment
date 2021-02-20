#include <iostream>

#include "DLList.h"
using namespace std;

int main()
{

	//testing initilization-success
	DLList<int> test;

	//test is list empty-success
	bool empty = test.isListEmpty();
	cout << empty << endl;
	//testing push front and back-success
	test.push_front(10);
	test.push_front(20);
	test.push_front(30);
	test.push_back(100);
	test.push_back(9);

	//test is list empty again-success
	empty = test.isListEmpty();
	cout << empty << endl;
	//test push mid-success
	test.push_mid(55, 1);
	//test pop front and back-success
	test.pop_front();
	test.pop_back();
	//test pop mid
	test.pop_mid(2);
	//test read front and back
	cout << test.front() << endl;
	cout << test.back() << endl;
	
	return 0;
}