#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node* insertAtEnd(Node *head, int data)
{
    Node *nd = new Node{data, nullptr};
    Node *temp{head};

    if(head == nullptr)
    {
        head = nd;
        head->next = head;
    }
    else
    {
        while(temp->next != head)
            temp = temp->next;

        nd->next = temp->next;
        temp->next = nd;
    }

    return head;
}

Node* insertAtBeg(Node *head, int data)
{
    
}

void traverseList(Node *head)
{
    Node *temp{head};

    while(temp->next != head)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << " -> ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    int data;
    Node *head{nullptr};

    while(true)
    {
        std::cout << "Insert an integer to to pushed in the circular linked list; Enter -1 to stop" << std::endl;
        std::cin >> data;

        if(data == -1)
            break;
        else
            head = insertAtEnd(head, data);
    }

    std::cout << "Initial list" << std::endl;
    traverseList(head);

    return 0;
}