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

Node* head;
Node* tail;

void initilize() {
	head = new Node;
	tail = new Node;
}

//insert node at front of list
void insertFront(int newData) {
	//allocate node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	//add data
	newNode->data = newData;
	newNode->next = head;
	newNode->prev = NULL;

	//change previous heads prev to this value
	if (head != NULL)
		head->prev = newNode;
	//move head to point to new node
	head = newNode;
}

//delete node at frontof list
void deleteFront(){
	if (head != NULL) {
		//create a  tempory node pointing to head
		Node* temp = head;

		//move head to next of head
		head = head->next;
		
		//delete temp node
		free(temp);
		//if new head is not null, make prev of new head null
		if (head != NULL)
			head->prev = NULL;
	}

}

//insert node at back of list
//delete node at back of list
void insertBack(struct Node** tailRef, int newData) {
	//allocate node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	//add data
	newNode->data = newData;
	newNode->next = NULL;
	newNode->prev = (*tailRef);

	//change previous tail references
	//if there is a tail reference
	if ((*tailRef) != NULL)
	//point it this way
		(*tailRef)->next = newNode;
}
void deleteBack(struct Node* tailRef) {
	if (tailRef != NULL) {
		Node* temp = tailRef;

		tailRef = tailRef->prev;

		free(temp);

		if (tailRef != NULL)
			tailRef->next = NULL;
	}
}

//insert node at arbitary location of list
//delete nose at arbitary location of list
void insertMid(struct Node* prevNode,int newData) {
	//check if prev node is null will fail if node is null
	if (prevNode == NULL) {
		
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	//update new nodes pointers
	newNode->data = newData;
	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	

	//update surrounding nodes
	prevNode->next = newNode;
	if (newNode->next != NULL)
		newNode->next->prev = newNode;

	
}
void deleteMid(struct Node* node) {
	//make sure there is a node to delete
	if (node != NULL) {
		//create temp node
		Node* temp = node;

		//shift around connections
		node->prev->next = node->next;
		node->next->prev = node->prev;

		//delete the temporary node
		free(temp);
		
	}
}

//return count of nodes in list
void countNodes();

//check if list is empty
void isListEmpty();

//returning first or last node in list
void returnFirst();
void returnLast();

//sort the list
void sortList();