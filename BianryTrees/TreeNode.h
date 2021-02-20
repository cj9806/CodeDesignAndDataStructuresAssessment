#pragma once

template<typename T>
class TreenODE
{
public:
	struct Node {
		T data;

		//node children
		Node* left;
		Node* right;
		Node* parent;

		bool hasLeft() const {
			if (left != nullptr)
				return true;
			else return false;
		} //const;
		bool hasRight() const {
			if (right != nullptr)
				return true;
			else return false;
		} //const;
	};
	//constructor sets root value to null
	TreenODE() {
		root = nullptr;
	}
	~TreenODE();

	//search binary tree for node with specified value
	//begin at root node
	// write the found node to the found variable OR write nullptr if none was found
	//returns true if a node was found
	//assumes given node is the root of the tree
	//please only use the root of the tree
	//not asking, genuinly think it will break the program if it dosn't 
	bool search(const T& value, Node*& found) {
		
		found = privSearch(value, root);
		//if the value exsists in the tree
		if (found != nullptr)
			//return true
			return true;
		//else 
		else {
			//write a nullptr to found
			found = nullptr;
			return false;
		}
	}

	//insert node into tree
	void insert(const T& value) {
		//search for node
		Node* temp = privSearch(value, root);
		//if node exsists
		if (temp->data == value)
			//do nothing
			return;
		//else node does not exsist
		else {
			//set value to new node->data
			temp->data == value;
			//return
			return;
		}
	}

	void remove(const T& value) {
		//search for specified node using given value will be reffered to as target node
		Node* temp = privSearch(value, root);
		//if value cannot be found
		if (temp->data == nullptr)
			//return that specified node or that it dosnt exsist or do nothing idfk
			return;
		//if node has no children
		if (temp->hasLeft() != true && temp->hasRight() != true) {
			//set parent nodes pointer to null
			if (temp->parent->right == temp)
				temp->parent->right = nullptr;
			else temp->parent->left = nullptr;
			delete temp;
		}
		//else if node to be deleated has one child
		//if only left child
		else if (temp->hasLeft() == true && temp->hasRight() == false) {
			//change targets parent pointer to point to child
			temp->left->prev = temp->prev;
			temp->prev->left = temp->left;
			//delete target node
			delete temp;
		}
		//if only right child
		else if(temp->hasRight){
			temp->right->prev = temp->prev;
			temp->prev->right = temp->right;

			delete temp;
		}

		//else if node had 2 children
		else
		{
			//step right once
			temp = temp->right;
			//step left as many times as possible
			while (temp->hasLeft()) 
			{
				temp = temp->left;
			}
			//copy value of the final node to target node
			head = temp;
			//if final node has a child(should only be able to have one)
			if (temp->hasRight())
			{
				//change final node's parent pointer to point to final nodes child
				//should only have right
				temp->parent->left = temp right;
				temp->right->parent = temp parent;
			}
			//else the node has no child to take care of
			else
			{
				temp->parent->left = nullptr;
			}
			delete temp;
		}

	};


private:
	Node* root;
	//------------------------------------------------------MINOR RESTRUCTURING REQUIRED------------------------------------------------------//

	//searches tree for specified value starting at given node
	Node* privSearch(const T& value, Node* root){
		Node* temp = root;
		//if node is current node
		if (temp->data == value) {
			return temp;
		}
		//current node has children
		//nod only has left
		else if (root->hasLeft() && root->hasRight() = false) {
			//move to the left node
			privSearch(value, temp->left);
		}
		//node only has right child
		else if (root->hasRight()&& root->hasLeft() = false){
			//move to the right node
			privSearch(value, temp->right);
		}
		//node has 2 children
		else if (root->hasRight() && root->hasLeft()) {
			//if value is less than root value
			if (value < root->data)
				//move left
				privSearch(value, temp->left);
			//else
			else
				//move right
				privSearch(value, temp->left);
		}
		//only other possibility is node has no child
		else
			//return new null node
			return nullptr;
		
			
		
	}
	//------------------------------------------------------MINOR RESTRUCTURING REQUIRED------------------------------------------------------//
};

