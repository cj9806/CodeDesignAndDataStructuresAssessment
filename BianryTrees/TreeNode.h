#pragma once

template<typename T>
class tBinaryTree
{
public:
	struct Node {
		T value;

		//node children
		Node* left;
		Node* right;
		Node* parent;

		bool hasLeft() const;
		bool hasRight() const;
	};

	tBinaryTree();
	~tBinaryTree();
	//search binary tree for node with specified value
	T search(const T& value) {
		//if node is current node
		//current node have children
			//if value less than current node & currentnode has left child
				//move to the left node
			//if value more than current node & currentnode has right child
				//move to the right node
			//return that no valid node exists
		//node has no child
			//return no valid node exsist
			
	}

	//insert node into tree
	void insert(const T& value) {
		//search for node
		//if node exsists
			//do nothing
		//else node does not exsist

	}

	void remove() {
		//search for specified node using given value will be reffered to as target node
		//if value cannot be found
			//return that specified node or that it dosnt exsist idfk
		//if node has no children
			//delete target node
			//set parent nodes pointer to null

		//else if node to be deleated has one child
			//change targets parent pointer to point to child
			//delete target node


		//else if node had 2 children
			//step right once
			//step left as many times as possible 
			//copy value of the final node to target node
			//delete final node
			//if final node has a child(should only be able to have one)
				//change final node's parent pointer to point to final nodes child

	};


private:
	std::vector<vertex*> vertices;

	vertex *root
};

