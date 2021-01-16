#include <iostream>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>

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

void inorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

void levelOrderTraversal(Node *root)
{
    if(root == nullptr)
        return;

    std::queue<Node*> traversalQueue;
    traversalQueue.push(root);

    while(!traversalQueue.empty())
    {
        Node *curr = traversalQueue.front();
        traversalQueue.pop();

        std::cout << curr->data << " ";
        if(curr->left != nullptr) traversalQueue.push(curr->left);
        if(curr->right != nullptr) traversalQueue.push(curr->right);
    }
}

void levelOrderTraversalLineByLine(Node *root)
{
    if(root == nullptr)
        return;

    std::queue<Node*> traversalQueue;
    traversalQueue.push(root);
    traversalQueue.push(nullptr);

    while(traversalQueue.size() > 1)
    {
        Node *curr = traversalQueue.front();
        traversalQueue.pop();

        if(curr == nullptr)
        {
            std::cout << std::endl;
            traversalQueue.push(nullptr);
            continue;
        }

        std::cout << curr->data << " ";
        if(curr->left != nullptr) traversalQueue.push(curr->left);
        if(curr->right != nullptr) traversalQueue.push(curr->right);
    }
}

// height of a tree = length (in terms of nodes) from root to the fartest leaf
int heightOfTree(Node* root)
{
    if(root != nullptr)
    {
        return std::max((1+heightOfTree(root->left)), (1+heightOfTree(root->right)));
    }

    return 0;
}

// size of a tree = number of nodes in the tree
int sizeOfTree(Node *root)
{
    if(root == nullptr)
        return 0;
    else
        return (1 + sizeOfTree(root->left) + sizeOfTree(root->right));
}

// print all nodes at a cetaing distance from root
void nodesAtDistanceFromRoot(Node* root, int k)
{
    if(root == nullptr)
        return;

    if(k == 0)
        std::cout << root->data << " ";    
    
    nodesAtDistanceFromRoot(root->left, k-1);
    nodesAtDistanceFromRoot(root->right, k-1);
}

int maximumNodeInTheTree(Node *root)
{
    if(root == nullptr)
        return INT_MIN;
    else
    {
        return std::max({root->data, maximumNodeInTheTree(root->left), maximumNodeInTheTree(root->right)});
    }
}

bool childrenSumProperty(Node *root)
{
    if(root == nullptr || ((root->left == nullptr) && (root->right == nullptr)))
        return true;
    else
    {
        int sum{0};
        if(root->left != nullptr) sum += root->left->data;
        if(root->right != nullptr) sum += root->right->data;
        return ((root->data == sum) && childrenSumProperty(root->left) && childrenSumProperty(root->right));
    }
}

bool isBalanced(Node *root)
{
    if(root == nullptr)
        return true;
    else
    {
        return((std::abs(heightOfTree(root->left) - heightOfTree(root->right) <= 1)) && (isBalanced(root->left)) && (isBalanced(root->right)));
    }
}

void printLeftViewOfTree(Node* root)
{
    if(root == nullptr)
        return;

    std::queue<Node*> traversalQueue;
    traversalQueue.push(root);

    while(!traversalQueue.empty())
    {
        int qSize = traversalQueue.size();
        std::cout << traversalQueue.front()->data << " " << std::endl;

        for(int i = 0; i < qSize; i++)
        {
            Node *curr = traversalQueue.front();
            traversalQueue.pop();

            if(curr->left != nullptr) traversalQueue.push(curr->left);
            if(curr->right != nullptr) traversalQueue.push(curr->right);
        }
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

    std::cout << std::endl;
    std::cout << "Depth first traversal" << std::endl;
    std::cout << "Inorder Traversal" << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal" << std::endl;
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal" << std::endl;
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "height of tree = " << heightOfTree(root) << std::endl;

    std::cout << std::endl;
    std::cout << "Size of tree = " << sizeOfTree(root) << std::endl;

    std::cout << std::endl;
    std::cout << "Printing all nodes at distance 2 from root" << std::endl;
    nodesAtDistanceFromRoot(root, 2);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Level order traversal" << std::endl;
    levelOrderTraversal(root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Level order traversal line by line" << std::endl;
    levelOrderTraversalLineByLine(root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Maximum element in the tree = " << maximumNodeInTheTree(root) << "; In case tree is empty INT_MIN for the system is printed" << std::endl;

    std::cout << std::endl;
    std::cout << "Left view of tree" << std::endl;
    printLeftViewOfTree(root);
    std::cout << std::endl;

    std::cout << std::endl;
    if(childrenSumProperty(root))
        std::cout << "Tree follows children sum property" << std::endl;
    else
        std::cout << "Tree doesn't follow children sum property" << std::endl;

    std::cout << std::endl;
    if(isBalanced(root))
        std::cout << "Tree is balanced" << std::endl;
    else
        std::cout << "Tree is not balanced" << std::endl;

    return 0;
}

// g++ -std=c++11 Tree.cpp -o Tree