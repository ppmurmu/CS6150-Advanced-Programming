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

int main()
{
    Stack s = Stack(10);
    s.push(10);
    s.push(20);
    s.print();
    cout << s.pop() << endl;
    s.print();
}