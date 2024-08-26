// Glenn Fortunato
// Assignment 2
// COP3530
// Implementation of a Binary Tree
#include<iostream>
#include <queue>
struct BinaryTreeNode {
	char key;
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(char key, int value) {
		this->key = key;
		this->value = value;
		left = NULL;
		right = NULL;
	}
	//prints out the keys in the tree inOrder
	void inOrderTraversal(BinaryTreeNode* node) {
		if (node != nullptr) {
			inOrderTraversal(node->left);
			std::cout << node->key << " ";
			inOrderTraversal(node->right);
		}

		else {
			return;
		}
	}
	//prints out the keys in the tree in preOrder
	void preOrderTraversal(BinaryTreeNode* node) {
		if (node != nullptr) {
			std::cout << node->key << " ";
			inOrderTraversal(node->left);
			inOrderTraversal(node->right);
		}
		else {
			return;
		}
	}
	//prints out the keys in the tree in postOrder
	void postOrderTraversal(BinaryTreeNode* node) {
		if (node != nullptr) {
			postOrderTraversal(node->left);
			postOrderTraversal(node->right);
			std::cout << node->key << " ";
		}
		else {
			return;
		}
	}

	//Searches and returns the node with the target key using DFS assuming it is
	// unique in the tree.
	BinaryTreeNode* DFS(BinaryTreeNode* node, char target) {
		if (node == nullptr) {
			return NULL;
		}

		if (node->key == target) {
			return node;
		}

		BinaryTreeNode* leftBranch = DFS(node->left, target);
		if (leftBranch != nullptr) {
			return leftBranch;
		}

		BinaryTreeNode* rightBranch = DFS(node->right, target);
		return rightBranch;
	}

	//Searches and returns the node with the target key using BFS assuming it is
	// unique in the tree.
	BinaryTreeNode* BFS(BinaryTreeNode* node, char target) {
		if (node == nullptr) {
			return NULL;
		}

		std::queue<BinaryTreeNode*> myQueue;
		myQueue.push(node);

		while (!myQueue.empty()) {
			BinaryTreeNode* current = myQueue.front();
			myQueue.pop();

			if (current->key == target) {
				return current;
			}

			if (current->left != nullptr) {
				myQueue.push(current->left);
			}
			if (current->right != nullptr) {
				myQueue.push(current->right);
			}
		}
		return nullptr;
	}
};


int main() {
	// Create a binary tree
	BinaryTreeNode* root = new BinaryTreeNode('A', 1);
	root->left = new BinaryTreeNode('B', 2);
	root->right = new BinaryTreeNode('C', 3);
	root->left->left = new BinaryTreeNode('D', 4);
	root->left->right = new BinaryTreeNode('E', 5);
	root->right->left = new BinaryTreeNode('F', 6);
	root->right->right = new BinaryTreeNode('G', 7);

	// Test in-order traversal
	std::cout << "In-order traversal: ";
	root->inOrderTraversal(root);
	std::cout << std::endl;

	// Test pre-order traversal
	std::cout << "Pre-order traversal: ";
	root->preOrderTraversal(root);
	std::cout << std::endl;

	// Test post-order traversal
	std::cout << "Post-order traversal: ";
	root->postOrderTraversal(root);
	std::cout << std::endl;

	// Test DFS
	char targetDFS = 'E';
	BinaryTreeNode* resultDFS = root->DFS(root, targetDFS);
	if (resultDFS != nullptr) {
		std::cout << "DFS: Found node with key '" << targetDFS << "' and value '"
			<< resultDFS->value << "'" << std::endl;
	}
	else {
		std::cout << "DFS: Node with key '" << targetDFS << "' not found." <<
			std::endl;
	}
	// Test BFS
	char targetBFS = 'F';
	BinaryTreeNode* resultBFS = root->BFS(root, targetBFS);
	if (resultBFS != nullptr) {
		std::cout << "BFS: Found node with key '" << targetBFS << "' and value '"<< resultBFS->value << "'" << std::endl;
	}
	else {
		std::cout << "BFS: Node with key '" << targetBFS << "' not found." <<
			std::endl;
	}
	return 0;
};

