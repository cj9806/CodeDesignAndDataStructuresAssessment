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
	//creates node with value of null
	DLList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//delete all nodes in list
	~DLList() {
		Node* temp = head;
		while (temp != tail) {
			temp = temp->next;
			delete temp->prev;
		}
		delete temp;
	}

	//insert node at front of list
	void push_front(const T& newData) {
		if (head != nullptr) {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = head;
			head->prev = temp;

			head = temp;
			count++;
		}
		else {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = nullptr;

			head = temp;
			tail = temp;
			count = 0;
		}
		
	}
	//delete node at front of list
	void pop_front() {
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
		if (head!= nullptr)
		{
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		
	}

	//insert node at back of list
	void push_back(const T& newData) {
		if (tail != nullptr) {
			Node* temp = new Node;
			temp->data = newData;
			temp->next = nullptr;
			temp->prev = tail;
			tail->next = temp;

			tail = temp;
			count++;
		}
		else {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = nullptr;

			head = temp;
			tail = temp;
			count = 0;
		}
	}
	//delete node at back of list
	void pop_back() {
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		count--;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}

	}

	//insert node at arbitary location of list
	//delete nose at arbitary location of list

	//will add node after given index, assumes index count starts at 0 
	//will add to tail of list if out of range
	void push_mid(const T& newData, int listIndex) {
		//INDEX given is out of range
		if (listIndex > count&& head != nullptr) {
			Node* temp = new Node;
			temp->data = newData;
			temp->next = nullptr;
			temp->prev = tail;

			tail = temp;
			count++;
		}
		else if (head != nullptr) {
			Node* seed = head;
			for (int i = 0; i < listIndex; i++) {
				seed = seed->next;
			}
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = seed;
			temp->next = seed->next;
			seed->next->prev = temp;
			seed->next = temp;
			count++;
		}
		//if no values in list
		else {
			Node* temp = new Node;
			temp->data = newData;
			temp->prev = nullptr;
			temp->next = nullptr;

			head = temp;
			tail = temp;
			count = 0;
		}
	}
	//assumes you want to delete a node at a certin index with index starting at 0
	//if index is  out of range it will pop the tail
	void pop_mid(int listIndex) {
		if (listIndex > count && head != nullptr)
		{
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
			count--;
			if (tail != nullptr) {
				tail->next = nullptr;
			}
			else {
				head = nullptr;
			}
		}
		else if (head != nullptr)
		{
			Node* temp = head;
			for (int i=0;i < listIndex;i++)
			{
				temp = temp->next;
			}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
		}
		
	}

	//returns the number of nodes in the list
	int countNodes() {
		return count+1;
	}

	//check if list is empty
	bool isListEmpty() {
		if (head == nullptr || tail == nullptr)
			return true;
		else return false;
	}

	//search for node and returns index of value in list 
	//returns -1 if value is not present in current list
	//jsut relized it neverasked for this
	//T search(const T& data) {
	//	//create temporary node pointing to head
	//	Node* temp = head;
	//	while(temp != tail)
	//	{
	//		if (temp->data == data)
	//			return temp->data;
	//		else 
	//			temp = temp->next;
	//	}
	//	return -1;
	//}

	T front() {
		//be sure to call it data not fucking value you idiot
		return head->data;
	}
	T back() {
		return tail->data;
	}
private:
	Node* head;
	Node* tail;
	int count = -1;
};

