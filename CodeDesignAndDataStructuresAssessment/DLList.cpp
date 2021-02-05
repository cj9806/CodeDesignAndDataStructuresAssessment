#include "DLList.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
//
struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};
//insert node at front of list
void insertFront() {}

//delete node at frontof list
void deleteFront(){}

//insert node at back of list
//delete node at back of list
void insertBack();
void deleteBack();

//insert node at arbitary location of list
//delete nose at arbitary location of list
void insertMid();
void deleteMid();

//return count of nodes in list
void countNodes();

//check if list is empty
void isListEmpty();

//returning first or last node in list
void returnFirst();
void returnLast();

//sort the list
void sortList();