#pragma once
class DLList
{	
public:
	struct Node {
		int data;   //data for element stored
		Node* prev; //pointer to previous node
		Node* next; //pointerto next node
	};
	
	void initilize();

	//insert node at front of list
	//delete node at front of list
	void insertFront(struct Node** headRef, int newData);
	void deleteFront();

	//insert node at back of list
	//delete node at back of list
	void insertBack(struct Node** tailRef, int newData);
	void deleteBack();

	//insert node at arbitary location of list
	//delete nose at arbitary location of list
	void insertMid(struct Node* prevNode, int newData);
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
private:
	Node* head;
	Node* tail;
};

