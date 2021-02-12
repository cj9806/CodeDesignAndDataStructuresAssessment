#pragma once
template<typename T>
class DLList
{	
public:
	struct Node {
		T data;   //data for element stored
		Node* prev; //pointer to previous node
		Node* next; //pointerto next node
	};
	
	//default constructor
	void DLList();

	//insert node at front of list
	//delete node at front of list
	void push_front(const T& newData) {
		if (head != nullptr) {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = head;

			head = temp;
		}
		else {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = nullptr;

			head = temp;
			tail = temp;
		}
	}
	void pop_front() {
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head!= nullptr)
		{
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		
	}

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
	int count = 0;
};

