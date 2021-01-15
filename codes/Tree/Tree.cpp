#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void insertRightChild(Node *&root);

void insertLeftChild(Node *&root)
{
    int data{0};
    std::cout << "Enter left child of " << root->data << std::endl;
    std::cin >> data;

    if(data == -1)
        return;
        
    Node *newNode = new Node{data, nullptr, nullptr};
    root->left = newNode;

    insertLeftChild(root->left);
    insertRightChild(root->left);
}

void insertRightChild(Node *&root)
{
    int data{0};
    std::cout << "Enter right child of " << root->data << std::endl;
    std::cin >> data;

    if(data == -1)
        return;
        
    Node *newNode = new Node{data, nullptr, nullptr};
    root->right = newNode;

    insertLeftChild(root->right);
    insertRightChild(root->right);
}

void inorderTraverse(Node* root)
{
    if(root != nullptr)
    {
        inorderTraverse(root->left);
        std::cout << root->data << " ";
        inorderTraverse(root->right);
    }
}

void preorderTraverse(Node* root)
{
    if(root != nullptr)
    {
        std::cout << root->data << " ";
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

void postorderTraverse(Node* root)
{
    if(root != nullptr)
    {
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        std::cout << root->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    // Create a new tree
    int data;
    Node *root{nullptr};

    std::cout << "*******************************************************************"  << std::endl;
    std::cout << "Rules to enter any data in the tree"  << std::endl;
    std::cout << "1. It should be an integer"  << std::endl;
    std::cout << "2. Enter -1 if you don't wwant to go further down the tree anywhere" << std::endl;
    std::cout << "*******************************************************************"  << std::endl;
    std::cout << std::endl;

    std::cout << "Enter root of binary search tree" << std::endl;
    std::cin >> data;

    if(data != -1)
    {
        Node *newNode = new Node{data, nullptr, nullptr};
        root = newNode;

        insertLeftChild(root);
        insertRightChild(root);
    }

    inorderTraverse(root);
    std::cout << std::endl;

    preorderTraverse(root);
    std::cout << std::endl;

    postorderTraverse(root);
    std::cout << std::endl;

    return 0;
}

// g++ -std=c++11 Tree.cpp -o Tree