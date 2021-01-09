#include <iostream>

struct Node
{
    int val;
    Node* next;
};

void traverse(Node* head)
{
    Node* temp; temp = head;
    if(temp == nullptr)
        std::cout << "list is empty" << std::endl;
    else
    {
        while(temp != nullptr)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void traverseRecc(Node* head)
{
    if(head == nullptr)
        return;
    else
    {
        std::cout << head->val << " -> ";
        traverseRecc(head->next);
    }
}

Node* insertBegin(Node *head, int val)
{
    Node *nd = new Node{val, nullptr};
    if(head == nullptr)
    {
        head = nd;
    }
    else
    {
        nd->next = head;
        head = nd;
    }

    return head;
}

Node* deleteBegin(Node *head)
{
    if(head == nullptr)
    {
        std::cout << "List is already empty; nothing to delete" << std::endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return head;
}

Node* insertEnd(Node *head, int val)
{
    Node *temp = head; 
    Node *nd = new Node{val, nullptr};
    if(head == nullptr)
    {
        head = nd;
    }
    else
    {
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = nd;
    }

    return head;
}

Node* deleteEnd(Node* head)
{
    if(head == nullptr)
        std::cout << "List is already empty; nothing to delete" << std::endl;
    else if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *temp1;

        while(temp->next->next != nullptr)
            temp = temp->next;

        temp1 = temp->next;
        temp->next = nullptr;
        delete temp1;
    }

    return head;
}

Node* insertAtPos(Node* head, int pos, int val)
{
    int size{0};

    Node *temp = head;
    while(temp != nullptr)
    {
        size++;
        temp = temp->next;
    }

    if(pos > size + 1)
        return head;

    Node *nd = new Node{val, nullptr};

    int count{1};
    Node *curr{head}, *prev{head};
    temp = head;

    if(pos == 1)
    {
        nd->next = head;
        head = nd;
    }
    else
    {
        while(temp != nullptr)
        {
            if(count == pos)
                break;

            prev = temp;
            temp = temp->next;
            curr = temp;

            count++;
        }

        nd->next = curr;
        prev->next = nd;
    }

    return head;
}


int main(int argc, char const *argv[])
{
    Node *head{nullptr}, *temp{nullptr};
    temp = head;
    int n;

    while(true)
    {
        std::cout << "Enter a new integer to insert in the linked list" << std::endl;
        std::cin >> n;

        if(n == -1)
            break;
        else
        {
            Node *nd = new Node{n, nullptr};

            if(head == nullptr)
            {
                head = nd;
                temp = head;
            }
            else
            {
                temp->next = nd;
                temp = temp->next;
            }
        }
    }

    // traverse(head);
    traverseRecc(head);
    std::cout << std::endl;

    // head = insertBegin(head, 10);
    // std::cout << "After inserting 10 at beginning of the list" << std::endl;
    // traverse(head);

    // head = insertEnd(head, 20);
    // std::cout << "After inserting 20 at end of the list" << std::endl;
    // traverse(head);

    // head = deleteBegin(head);
    // std::cout << "After deleting at beginning of list" << std::endl;
    // traverse(head);

    // head = deleteEnd(head);
    // std::cout << "After deleting at end of list" << std::endl;
    // traverse(head);

    head = insertAtPos(head, 3, 234);
    std::cout << "After inserting 234 at pos = 1 of list" << std::endl;
    traverse(head);    

    return 0;
}

// g++ -std=c++11 create.cpp -o create