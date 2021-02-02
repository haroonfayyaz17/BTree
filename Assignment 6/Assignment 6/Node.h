
#pragma once
class Node {
	int *keys;
	int M;
	Node **childPtr;
	int n;
	bool leaf;

public:
	Node(int _t, bool _leaf);

	void displayTree(System::Windows::Forms::RichTextBox^ rich);

	int searchKey(int keyValue);
	void insertNonFull(int keyValue);
	void splitChild(int i, Node *y);
	void deleteKey(int keyValue);
	void removeLeafKey(int indexValue);
	void removeFromNonLeaf(int indexValue);
	int getPredecessor(int indexValue);
	int getSuccessor(int indexValue);
	void fill(int indexValue);
	void borrowFromPreviousNode(int indexValue);
	void borrowFromNextNode(int indexValue);
	void mergeNodes(int indexValue);

	friend class BTree;
};
