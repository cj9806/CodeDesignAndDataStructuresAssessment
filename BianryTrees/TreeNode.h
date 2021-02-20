#pragma once

template<typename T>
class TreeNode
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
	TreeNode() {
		
	}
	~TreeNode() {
		destroyRecursive(root);
	};

	//search binary tree for node with specified value
	//begin at root node
	// write the found node to the found variable OR write nullptr if none was found
	bool search(const T& value) {
		
		Node* found = privSearch(value, root);
		//if the value exsists in the tree
		if (found->data == value)
			//return true
			return true;
		//else 
		else {
			//write a nullptr to found
			return false;
			found = nullptr;
		}
	}

	//insert node into tree
	void insert(const T& value) {
		//search for node
		if (root != nullptr) {
			Node* temp = privSearch(value, root);
			//if root exsists
			if (root != nullptr) {
				//if value exsist in tree
				if (temp->data == value)
					//do nothing
					return;
				//else node does not exsist
				else {
					//set value to new node->data
					temp->data = value;

					//return
					return;
				}
			}
		}
		else {
			Node* temp = new Node;
			temp->data = value;
			temp->parent = nullptr;
			temp->left = nullptr;
			temp->right = nullptr;
			root = temp;
		}
	}

	void remove(const T& value) {
		//search for specified node using given value will be reffered to as target node
		Node* temp = privSearch(value, root);
		//if value cannot be found
		if (temp->data != value)
			//return that specified node or that it dosnt exsist or do nothing idfk
			return;
		//if node has no children
		else if (temp->hasLeft() != true && temp->hasRight() == false) {
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
			temp->left->parent = temp->parent;
			temp->parent->left = temp->left;
			//delete target node
			delete temp;
		}
		//if only right child
		else if(temp->hasRight() && temp->hasRight() == false){
			temp->right->parent = temp->parent;
			temp->parent->right = temp->right;

			delete temp;
		}

		//else if node had 2 children
		else
		{
			//find the value on the tree greater than the one we want to remove
			Node* toDelete = temp;
			//step right once
			temp = temp->right;
			//step left as many times as possible to get temp to be final node
			while (temp->hasLeft()) 
			{
				temp = temp->left;
			}
			//copy value of the final node to target node
			temp->data = toDelete->data;
			//if final node has a child(should only be able to have one)
			if (temp->hasRight())
			{
				//change final node's parent pointer to point to final nodes child
				//should only have right
				temp->parent->left = temp->right;
				temp->right->parent = temp->parent;
			}
			//else the node has no child to take care of
			else
			{
				temp->parent->left = toDelete->left;
			}
			delete temp;
		}

	};


private:
	Node* root;
	//------------------------------------------------------MINOR RESTRUCTURING REQUIRED------------------------------------------------------//

	//searches tree for specified value starting at given node
	Node* privSearch(const T& value, Node* node){
		node;
			//if node is current node
		if (node->data == value) {
			return node;
		}
		//current node has children
		//nod only has left
		else if (node->hasLeft() && value < node->data) {
			//move to the left node
			privSearch(value, node->left);
		}
		//node only has right child
		else if (node->hasRight() && value > node->data) {
			//move to the right node
			privSearch(value, node->right);
		}
		//node has 2 children
		else if (node->hasRight() && node->hasLeft()) {
			//if value is less than root value
			if (value < node->data)
				//move left
				privSearch(value, node->left);
			//else
			else
				//move right
				privSearch(value, node->left);
		}
		//only other possibility is node does not exsist
		else {
			//return new null node
			Node* child = new Node;
			child->parent = node;
			child->left = nullptr;
			child->right = nullptr;
			if (value > node->data) {
				node->right = child;
			}
			else {
				node->left = child;
			}
			return child;
		}
	}
	//------------------------------------------------------MINOR RESTRUCTURING REQUIRED------------------------------------------------------//
	void destroyRecursive(Node* boom) {
		if (boom) {
			destroyRecursive(boom->left);
			destroyRecursive(boom->right);
			delete boom;
		}
	}
};

