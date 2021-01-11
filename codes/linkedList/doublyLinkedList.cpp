#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node* insertAtBeg(Node* head, int data)
{
    Node *nd = new Node{data, nullptr, nullptr};

    if(head == nullptr)
    {
        head = nd;
    }
    else
    {
        nd->next = head;
        head->prev = nd;
        head = nd;
    }

    return head;
}

Node* insertAtEnd(Node* head, int data)
{
    Node *nd = new Node{data, nullptr, nullptr};
    Node *temp{head};

    if(head == nullptr)
    {
        head = nd;
    }
    else
    {
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = nd;
        nd->prev = temp;
        temp = nd;
    }

    return head;
}

Node* reverseList(Node* head)
{
    Node *temp{head}, *newHead{nullptr};

    while(temp != nullptr)
    {
        newHead = insertAtBeg(newHead, temp->data);
        temp = temp->next;
    }

    return newHead;
}

void traverseList(Node* head)
{
    Node* temp{head};

    while(temp != nullptr)
    {
        std::cout << temp->data << " <=> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    int data;
    Node *head{nullptr};

    while(true)
    {
        std::cout << "Enter an integer to be inserted at the end of the doubly linked list; Enter -1 to stop" << std::endl;
        std::cin >> data;

        if(data == -1)
            break;
        else
            head = insertAtEnd(head, data);
    }

    std::cout << "Initial list" << std::endl;
    traverseList(head);

    Node *newHead = reverseList(head);
    std::cout << "Reversed list" << std::endl;
    traverseList(newHead);

    return 0;
}

// g++ -std=c++11 doublyLinkedList.cpp -o doublyLinkedList