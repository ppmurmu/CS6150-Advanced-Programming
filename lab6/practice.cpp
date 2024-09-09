#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int capacity;
    Stack(int capacity)
    {

        arr = new int[capacity];
        this->capacity = capacity;
        top = -1;
    }
    void push(int n)
    {
        if (top == capacity - 1)
        {
            cout << capacity << endl;
            cout << "stack overflow";
            return;
        }
        top++;
        arr[top] = n;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "stack empty" << endl;
            return -1;
        }
        return arr[top];
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "stack empty" << endl;
            return -1;
        }
        int t = arr[top];
        top--;
        return t;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    int size()
    {
        return top + 1;
    }
    void print()
    {
        for (int i = 0; i < top + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
    Queue(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        front = 0;
        rear = -1;
    }
    void push(int n)
    {
        if (count == capacity - 1)
        {
            cout << "queue overflow";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = n;
        count++;
    }
    int pop()
    {
        if (count == 0)
        {
            cout << "queue empty";
        }
        int t = arr[front];
        front = (front + 1) % capacity;
        count--;
        return t;
    }
    int peep()
    {
        if (count == 0)
        {
            cout << "queue empty";
        }
        return arr[front];
    }
    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }
};

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
    void setNext(Node *n)
    {
        next = n;
    }
};
class LinkedList
{
public:
    Node *head;
    void addNode(int val)
    {
        Node *n = new Node(10);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            head->setNext(n);
        }
    }
    void print()
    {
        Node *t = head;
        while (t != NULL)
        {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
};

class StackLL
{
    LinkedList stack;
    Node *top;
    StackLL()
    {
        stack = LinkedList();
        top = NULL;
    }
    void push(int n)
    {
        if (top == NULL)
        {
            top = new Node(n);
            stack.addNode(n);
        }
        else
        {
            top->setNext(n);
            stack.addNode(n);
        }
    }
};

int main()
{
    LinkedList l = LinkedList();

    l.addNode(10);
    l.addNode(10);
    l.print();
}