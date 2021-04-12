#include <iostream>
#include <cstddef>
#include <type_traits>

 class Node {
	 
 public:std::string data;
 public:struct Node* left;
 public:struct Node* right;

	 
 public: Node(std::string data) {
		 data = data;
		 left = std::nullptr_t(NULL);
		 right = std::nullptr_t(NULL);
	 }

	  void setLeft(Node *newLeft) {
		  left = newLeft;
	  }
	  void setRight(Node* newRight) {
		  right = newRight;
	  }

	  Node getLeft() {
		  return *left;
	  }
	  Node getRight() {
		  return *right;
	  }
	  std::string getData() {
		  return data;
	  }
	  void setData(std::string newNumber) {
		  data = newNumber;
	  }

};


 
 