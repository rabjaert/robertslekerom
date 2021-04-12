#include <iostream>
#include "node.cpp"



struct BinaryTree {

	Node *rootNode;
	
	


public:BinaryTree()

{
	
	rootNode = NULL;
}

	void insertWord(std::string word) {
		rootNode = insertNode(rootNode, word);
	}

private:Node* insertNode(Node* node, std::string word) {

		if (node == NULL)
		{
			node = new Node(word);
		}
		else if (word.compare(node->data) < 0)
		{
			node->left = insertNode(node->left, word);
		}
		else
		{
			node->right = insertNode(node->right, word);
		}
		return node;
		//deleting pointer
		delete node;
	
	}

private:void traverseXNodes(Node *node) {
		
	

	if (node == NULL) {
			return;
		}
		else {
			traverseXNodes(node->left);
			std::cout << node << std::endl;
			traverseXNodes(node->right);
			
		}
	delete node;
	}
public:void print() {
	traverseXNodes(rootNode);
}

	  

};
 
