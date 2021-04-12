#include "binarytree.cpp"
#include <iostream>
#include <vector>

int main() {

	
BinaryTree bin;
constexpr size_t SIZE = 12;
int start;
	
for(start = 0; start < SIZE; start++) 
 
	{	
		if (start == 5) {
			bin.insertWord("niklas");
		}
		bin.insertWord("appelsin");
		bin.insertWord("niklas");
	}
 bin.insertWord("appelsin");
 bin.insertWord("niklas");
 bin.insertWord("is");
 bin.insertWord("iskrem");
 
 bin.contains("niklas");
 bin.contains("appelsin");
 bin.contains("is");
 bin.contains("jævel");







bin.print();



return 0;
	
	


}