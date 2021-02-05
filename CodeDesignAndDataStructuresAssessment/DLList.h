#pragma once
template<typename DLL>
class DLList
{
	struct node {
		Dll data;   //data for element stored
		node* prev; //pointer to previous node
		node* next; //pointerto next node
	};
	node* head; //pointer to front of list
	node* tail; //ponter to back of list
public:
	
	DLList(); //initilize head and tail to null
	~DLList();//delete all nodes

	//insert node at front of list
	//delete node at front of list
	void insertFront(const DLL& val);
	void deleteFront();

	//insert node at back of list
	//delete node at back of list
	void insertBack(const T& val);
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

