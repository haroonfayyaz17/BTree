#include "Node.h"
#include <string>
using namespace std;
#pragma once
class BTree {
	Node *root;
	int M;
	

public:
	BTree(int t) {
		root = nullptr;
		M = t;
	}
	/*void init(int t){
		M = t;
	}*/


	void displayTree(System::Windows::Forms::RichTextBox^ rich) {
		if (root != nullptr)
			root->displayTree(rich);
	}
	void insertKey(int keyValue);

	void deleteKey(int keyValue);
};
