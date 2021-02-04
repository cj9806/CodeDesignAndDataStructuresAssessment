#pragma once
class DLList
{
public:
	struct Node {};
	//insert node at front of list
	//delete node at front of list
	void insertFront(struct Node* headRef,int newDataFront);
	void deleteFront();

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
private:
};

