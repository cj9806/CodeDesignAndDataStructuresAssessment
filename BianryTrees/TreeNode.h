#pragma once

template<typename T>
class tBinaryTree
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

	tBinaryTree();
	~tBinaryTree();

	//search binary tree for node with specified value
	//begin at root node
	//returns new empty node if there is no valid node
	Node* search(const T& value, Node* root) {
		Node* temp = root;
		//if node is current node
		if (temp->data == value) {
			return temp;
		}
		//current node have children
		else if (temp->hasLeft() && temp->hasRight) {
			//if value less than current node & currentnode has left child
			if (temp->data < value) {
				//move to the left node
				search(value, temp->left);
			}
			//if value more than current node & currentnode has right child
			if (temp->data > value) {
				//move to the right node
				search(value, temp->right);
			}
		}
		//only other possibility is node has no child
		else {
			//return new null node
			Node* temp2 = new Node;
			temp2->parent = temp;
		}
	}

	//insert node into tree
	void insert(const T& value) {
		//search for node
		Node* temp = search(value, root);
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
		Node* temp = search(value, root);
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
		else if(temp->){
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
				if (temp->hasLeft() = false) {
					break;
				}
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
			else
			{
				temp->parent->left = nullptr;
			}
			delete temp;
		}

	};


private:
	Node *root
};

