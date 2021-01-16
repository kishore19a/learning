#include <iostream>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

void insert(Node* &root, int data)
{
	if(root == nullptr)
	{
		Node *newNode = new Node{data, nullptr, nullptr};
		root = newNode;
	}
	else
	{
		if(data < root->data)
			insert(root->left, data);
		else
			insert(root->right, data);
	}
}

bool search(Node *root, int data)
{
	if(root != nullptr)
	{
		if(data == root->data)
			return true;
		else if (data < root->data)
			search(root->left, data);
		else
			search(root->right, data);
	}
	else
		return false;
}

void inorderTraversal(Node* root)
{
	if(root != nullptr)
	{
		inorderTraversal(root->left);
		std::cout << root->data << " ";
		inorderTraversal(root->right);
	}
}

int main(int argc, char const *argv[])
{
	int data;
	Node *root{nullptr};

	std::cout << "----------- Constructing a BST; Insert -1 to stop ------------" << std::endl;
	while(true)
	{
		std::cout << "Insert an item in the BST" << std::endl;
		std::cin >> data;

		if(data == -1)
			break;

		insert(root, data);
	}

	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Enter an element to search" << std::endl;
	std::cin >> data;

	if(search(root, data))
		std::cout << data << " is there in the BST" << std::endl;
	else
		std::cout << data << " is not present in the BST" << std::endl;

	return 0;
}

// g++ -std=c++11 BST.cpp -o BST