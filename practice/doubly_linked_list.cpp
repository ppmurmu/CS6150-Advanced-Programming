#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
    void setLeft(Node *n)
    {
        left = n;
    }
    void setRight(Node *n)
    {
        right = n;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *rear;
    LinkedList()
    {
        head = NULL;
        rear = NULL;
    }
    void addNode(int t)
    {
        Node *n = new Node(t);
        if (head == NULL)
        {
            head = n;
            rear = n;
            return;
        }
        Node *temp = rear;
        rear->setRight(n);
        rear = n;
        rear->left = temp;
    }
    void printFromHead()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        cout << endl;
    }
    void printFromRear()
    {
        Node *curr = rear;

        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->left;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList myList = LinkedList();
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(4);
    myList.addNode(5);
    myList.addNode(6);
    myList.printFromHead();
    myList.printFromRear();
    return 0;
}