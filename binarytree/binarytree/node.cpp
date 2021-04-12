#include <iostream>


 struct Node {
	 
 public:std::string data;
 public:struct Node* left;
 public:struct Node* right;

	 
 public: Node(std::string data) {
		 this->data = data;
		 left = NULL;
		 right = NULL;
	 }

};


 
 