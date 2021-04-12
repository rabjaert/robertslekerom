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

	void contains(std::string data) {
		
		containsHelper(rootNode, data);
		
	}
	bool containsHelper(Node* root, std::string data) {
		{
				if (root == NULL) {
					
					return false;
				}
				else if (data.compare(root->data) < 0)
				{
					root = root->left;
				}

				else if (data.compare(root->data) > 0)
				{
					root = root->right;
				}
				
				else
				return true;

			}
		
		return false;
	}

private:Node* insertNode(Node* node, std::string word) {

		if (node == NULL)
		{
			return new Node(word);
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
	}

	   


private:void traverseXNodes(Node *node) {
		
	if (node == NULL) {
			return;
		}
		else {
			traverseXNodes(node->left);
			std::cout << node->data << std::endl;
			traverseXNodes(node->right);
			
		}
	
	}
public:void print() {
	traverseXNodes(rootNode);
}

	

};
 
