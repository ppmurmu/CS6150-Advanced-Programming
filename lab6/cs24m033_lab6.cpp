#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* No other header file should be used */

class LIFO
{
public:
    int db[3000];
    int db_size;
    int cache[10001];
    int top;
    LIFO(int size)
    {
        db_size = size;
        top = -1;
        for (int i = 0; i < 10001; i++)
        {
            cache[i] = -1;
        }
    }
    void put(int key, int value)
    {
        if (cache[key] != -1)
        {
            cache[key] = value;
            return;
        }
        if (top == db_size - 1)
        {
            cache[db[top]] = -1;
            db[top] = key;
            cache[key] = value;

            return;
        }
        top++;
        db[top] = key;
        cache[key] = value;
    }
    int get(int k)
    {
        if (cache[k] == -1)
        {
            return -1;
        }

        return cache[k];
    }
    void print()
    {
        if (top > -1)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << db[i] << " ";
            }
        }
        cout << endl;
    }
};

class Node
{
public:
    int val;
    int key;
    Node *left;
    Node *right;
    Node(int k, int v)
    {
        val = v;
        key = k;
        left = NULL;
        right = NULL;
    }
};

class LRU
{
public:
    Node *dbPointer[10001];
    int cache[10001];
    Node *front;
    Node *rear;
    int capacity;
    int curr;

    LRU(int n)
    {
        capacity = n;
        curr = 0;
        front = NULL;
        rear = NULL;
        for (int i = 0; i < 10001; i++)
        {
            cache[i] = -1;
            dbPointer[i] = NULL;
        }
    }

    int get(int k)
    {
        if (cache[k] == -1 || dbPointer[k] == NULL)
        {
            return -1;
        }

        Node *t = dbPointer[k];
        int tempVal = t->val;

        // Remove node from its current position
        if (t->left)
            t->left->right = t->right;
        else
            front = t->right;

        if (t->right)
            t->right->left = t->left;
        else
            rear = t->left;

        // Move to rear
        if (rear)
        {
            rear->right = t;
            t->left = rear;
            t->right = NULL;
            rear = t;
        }
        else
        {
            front = rear = t;
            t->left = t->right = NULL;
        }

        return tempVal;
    }

    void put(int key, int val)
    {
        if (dbPointer[key] != NULL)
        {
            // Key exists, update value and move to rear
            dbPointer[key]->val = val;
            get(key); // This will move the node to rear
            return;
        }

        Node *newNode = new Node(key, val);

        if (curr == capacity)
        {
            // Remove from front
            Node *temp = front;
            front = front->right;
            if (front)
                front->left = NULL;
            else
                rear = NULL;

            cache[temp->key] = -1;
            dbPointer[temp->key] = NULL;
            delete temp;
            curr--;
        }

        // Add new node to rear
        if (rear)
        {
            rear->right = newNode;
            newNode->left = rear;
            rear = newNode;
        }
        else
        {
            front = rear = newNode;
        }

        cache[key] = val;
        dbPointer[key] = newNode;
        curr++;
    }

    void print()
    {
        Node *t = rear;
        while (t != NULL)
        {
            cout << t->key << " ";
            t = t->left;
        }
        cout << endl;
    }
};

int main()
{
    freopen("my_output.txt", "w", stdout);
    ifstream inputFile("inp10.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    string inp = "";
    LIFO lifo = LIFO(0);
    LRU lru = LRU(0);
    string cat = "";
    cout << inp << endl;
    while (inp != "done")
    {

        inputFile >> inp;
        if (inp == "LIFO")
        {
            cat = "LIFO";
            int size;
            inputFile >> size;
            lifo = LIFO(size);
        }
        if (inp == "put" && cat == "LIFO")
        {
            int k, val;
            inputFile >> k >> val;
            lifo.put(k, val);
        }
        if (inp == "get" && cat == "LIFO")
        {
            int val;
            inputFile >> val;
            cout << lifo.get(val) << endl;
        }
        if (inp == "done")
        {
            break;
        }

        if (inp == "print" && cat == "LIFO")
        {
            lifo.print();
        }
        if (inp == "LRU")
        {
            cat = "LRU";
            int size;
            inputFile >> size;
            lru = LRU(size);
        }

        if (inp == "put" && cat == "LRU")
        {
            int k, val;
            inputFile >> k >> val;
            lru.put(k, val);
        }
        if (inp == "get" && cat == "LRU")
        {
            int val;
            inputFile >> val;
            int temp = lru.get(val);
            cout << temp << endl;
        }
        if (inp == "done")
        {
            break;
        }

        if (inp == "print" && cat == "LRU")
        {
            lru.print();
        }
    }

    return 0;
}