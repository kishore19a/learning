#include <iostream>
#include <queue>

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

Node* getSucssesor(Node *root)
{
    Node *temp{root->right};
    while(temp != nullptr && temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node* deleteNode(Node *root, int data)
{
    if(root == nullptr) return root;
    else if(root->data > data)
        root->left = deleteNode(root->left, data);
    else if(root->data < data)
        root->right = deleteNode(root->right, data);
    else
    {
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            Node *temp = getSucssesor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}

void levelOrderTraversalLineByLine(Node *root)
{
    if(root == nullptr)
        return;

    std::queue<Node*> traversalQueue;
    traversalQueue.push(root);

    while(!traversalQueue.empty())
    {
        int qSize = traversalQueue.size();
        for(int i = 0; i < qSize; i++)
        {
            Node *temp = traversalQueue.front();
            traversalQueue.pop();

            std::cout << temp->data << " ";
            if(temp->left != nullptr) traversalQueue.push(temp->left);
            if(temp->right != nullptr) traversalQueue.push(temp->right);
        }
        std::cout << std::endl;
    }
}

Node* floorOfBST(Node *root, int data)
{
    Node *temp{root}, *prev{nullptr};
    if(temp == nullptr) return temp;

    while(temp != nullptr)
    {
        prev = temp;

        if(data == temp->data)
            return temp;
        else if(data > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if(prev != nullptr)
        if(data < prev->data)
            return nullptr;

    return prev;
}

Node* ceilOfBST(Node *root, int data)
{
    Node *temp{root}, *res{nullptr};
    if(temp == nullptr) return temp;

    while(temp != nullptr)
    {
        if(data == temp->data)
            return temp;
        else if(data > temp->data)
            temp = temp->right;
        else
        {
            res = temp;
            temp = temp->left;
        }
    }

    if(res != nullptr)
        if(data > res->data)
            return nullptr;

    return res;
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

    std::cout << std::endl;
    std::cout << "Initial tree structure" << std::endl;
    levelOrderTraversalLineByLine(root);
    std::cout << std::endl;

    std::cout << "Enter an element to search" << std::endl;
    std::cin >> data;

    if(search(root, data))
        std::cout << data << " is there in the BST" << std::endl;
    else
        std::cout << data << " is not present in the BST" << std::endl;

    // std::cout << std::endl;
    // std::cout << "Enter an element to delete" << std::endl;
    // std::cin >> data;

    // std::cout << std::endl;
    // root = deleteNode(root, data);
    // std::cout << "New tree structure" << std::endl;
    // levelOrderTraversalLineByLine(root);
    // std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Enter an element to find floor of" << std::endl;
    std::cin >> data;
    Node *floor = floorOfBST(root, data);
    if(floor == nullptr) std::cout << "No element smaller than " << data << " found" << std::endl;
    else std::cout << "Element smaller than " << data << " found in BST = " << floor->data << std::endl;

    std::cout << std::endl;
    std::cout << "Enter an element to find ceil of" << std::endl;
    std::cin >> data;
    Node *ceil = ceilOfBST(root, data);
    if(ceil == nullptr) std::cout << "No element greater than " << data << " found" << std::endl;
    else std::cout << "Element greater than " << data << " found in BST = " << ceil->data << std::endl;

    return 0;
}

// g++ -std=c++11 BST.cpp -o BST