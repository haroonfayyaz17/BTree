#include "BTree.h"
#include <iostream>
using namespace std;
Node::Node(int M1, bool leaf1) {
	M = M1;
	leaf = leaf1;

	keys = new int[M - 1];
	childPtr = new Node *[M];

	n = 0;
}

int Node::searchKey(int keyValue) {
	int indexValue = 0;
	while (indexValue < n && keys[indexValue] < keyValue)
		++indexValue;
	return indexValue;
}

void Node::deleteKey(int keyValue) {
	int indexValue = searchKey(keyValue);

	if (indexValue < n && keys[indexValue] == keyValue) {
		if (leaf)
			removeLeafKey(indexValue);
		else
			removeFromNonLeaf(indexValue);
	}
	else {
		if (leaf) {
			cout << "The key " << keyValue << " is does not exist in the tree\n";
			return;
		}

		bool flag = ((indexValue == n) ? true : false);

		if (childPtr[indexValue]->n < M)
			fill(indexValue);

		if (flag && indexValue > n)
			childPtr[indexValue - 1]->deleteKey(keyValue);
		else
			childPtr[indexValue]->deleteKey(keyValue);
	}
	return;
}

void Node::removeLeafKey(int indexValue) {
	for (int i = indexValue + 1; i < n; ++i)
		keys[i - 1] = keys[i];

	n--;

	return;
}


void Node::removeFromNonLeaf(int indexValue) {
	int keyValue = keys[indexValue];

	if (childPtr[indexValue]->n >= M) {
		int pred = getPredecessor(indexValue);
		keys[indexValue] = pred;
		childPtr[indexValue]->deleteKey(pred);
	}

	else if (childPtr[indexValue + 1]->n >= M) {
		int succ = getSuccessor(indexValue);
		keys[indexValue] = succ;
		childPtr[indexValue + 1]->deleteKey(succ);
	}

	else {
		mergeNodes(indexValue);
		childPtr[indexValue]->deleteKey(keyValue);
	}
	return;
}

int Node::getPredecessor(int indexValue) {
	Node *cur = childPtr[indexValue];
	while (!cur->leaf)
		cur = cur->childPtr[cur->n];

	return cur->keys[cur->n - 1];
}

int Node::getSuccessor(int indexValue) {
	Node *cur = childPtr[indexValue + 1];
	while (!cur->leaf)
		cur = cur->childPtr[0];

	return cur->keys[0];
}

void Node::fill(int indexValue) {
	if (indexValue != 0 && childPtr[indexValue - 1]->n >= M)
		borrowFromPreviousNode(indexValue);

	else if (indexValue != n && childPtr[indexValue + 1]->n >= M)
		borrowFromNextNode(indexValue);

	else {
		if (indexValue != n)
			mergeNodes(indexValue);
		else
			mergeNodes(indexValue - 1);
	}
	return;
}

void Node::borrowFromPreviousNode(int indexValue) {
	Node *child = childPtr[indexValue];
	Node *sibling = childPtr[indexValue - 1];

	for (int i = child->n - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];

	if (!child->leaf) {
		for (int i = child->n; i >= 0; --i)
			child->childPtr[i + 1] = child->childPtr[i];
	}

	child->keys[0] = keys[indexValue - 1];

	if (!child->leaf)
		child->childPtr[0] = sibling->childPtr[sibling->n];

	keys[indexValue - 1] = sibling->keys[sibling->n - 1];

	child->n += 1;
	sibling->n -= 1;

	return;
}

void Node::borrowFromNextNode(int indexValue) {
	Node *child = childPtr[indexValue];
	Node *sibling = childPtr[indexValue + 1];

	child->keys[(child->n)] = keys[indexValue];

	if (!(child->leaf))
		child->childPtr[(child->n) + 1] = sibling->childPtr[0];

	keys[indexValue] = sibling->keys[0];

	for (int i = 1; i < sibling->n; ++i)
		sibling->keys[i - 1] = sibling->keys[i];

	if (!sibling->leaf) {
		for (int i = 1; i <= sibling->n; ++i)
			sibling->childPtr[i - 1] = sibling->childPtr[i];
	}

	child->n += 1;
	sibling->n -= 1;

	return;
}

void Node::mergeNodes(int indexValue) {
	Node *child = childPtr[indexValue];
	Node *sibling = childPtr[indexValue + 1];

	child->keys[M - 1] = keys[indexValue];

	for (int i = 0; i < sibling->n; ++i)
		child->keys[i + M] = sibling->keys[i];

	if (!child->leaf) {
		for (int i = 0; i <= sibling->n; ++i)
			child->childPtr[i + M] = sibling->childPtr[i];
	}

	for (int i = indexValue + 1; i < n; ++i)
		keys[i - 1] = keys[i];

	for (int i = indexValue + 2; i <= n; ++i)
		childPtr[i - 1] = childPtr[i];

	child->n += sibling->n + 1;
	n--;

	delete (sibling);
	return;
}

void BTree::insertKey(int keyValue) {
	if (root == NULL) {
		root = new Node(M, true);
		root->keys[0] = keyValue;
		root->n = 1;
	}
	else {
		if (root->n == 2 * M - 1) {
			Node *s = new Node(M, false);

			s->childPtr[0] = root;

			s->splitChild(0, root);

			int i = 0;
			if (s->keys[0] < keyValue)
				i++;
			s->childPtr[i]->insertNonFull(keyValue);

			root = s;
		}
		else
			root->insertNonFull(keyValue);
	}
}

void Node::insertNonFull(int keyValue) {
	int i = n - 1;

	if (leaf == true) {
		while (i >= 0 && keys[i] > keyValue) {
			keys[i + 1] = keys[i];
			i--;
		}

		keys[i + 1] = keyValue;
		n = n + 1;
	}
	else {
		while (i >= 0 && keys[i] > keyValue)
			i--;

		if (childPtr[i + 1]->n == 2 * M - 1) {
			splitChild(i + 1, childPtr[i + 1]);

			if (keys[i + 1] < keyValue)
				i++;
		}
		childPtr[i + 1]->insertNonFull(keyValue);
	}
}

void Node::splitChild(int i, Node *y) {
	Node *newNode = new Node(y->M, y->leaf);
	newNode->n = M - 1;

	for (int j = 0; j < M - 1; j++)
		newNode->keys[j] = y->keys[j + M];

	if (y->leaf == false) {
		for (int j = 0; j < M; j++)
			newNode->childPtr[j] = y->childPtr[j + M];
	}

	y->n = M - 1;

	for (int j = n; j >= i + 1; j--)
		childPtr[j + 1] = childPtr[j];

	childPtr[i + 1] = newNode;

	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];

	keys[i] = y->keys[M - 1];

	n = n + 1;
}



void Node::displayTree(System::Windows::Forms::RichTextBox^ rich) {
	rich->Text += "\n";
	int i;
	for (i = 0; i < n; i++) {
		if (leaf == false)
			childPtr[i]->displayTree(rich);
		rich->Text += keys[i]; 
		rich->Text += " ";
	}

	if (leaf == false)
		childPtr[i]->displayTree(rich);
}

void BTree::deleteKey(int keyValue) {
	if (!root) {
		//cout << "The tree is empty\n";
		return;
	}

	root->deleteKey(keyValue);

	if (root->n == 0) {
		Node *tmp = root;
		if (root->leaf)
			root = NULL;
		else
			root = root->childPtr[0];

		delete tmp;
	}
	return;
}
