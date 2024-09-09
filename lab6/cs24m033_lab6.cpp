#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/* No other header file should be used */



class LIFO {
    public:
    int db[3000];
    int db_size;
    int cache[10001];
    int top;
    LIFO(int size)
    {
        db_size=size;
        top=-1;
        for(int i=0; i< 10001; i++)
        {
            cache[i]=-1;
        }
    }
    void put(int key, int value)
    {
        if(top==db_size-1)
        {
            cache[db[top]]=-1;
            db[top]=key;
            cache[key]=value;

            return;
        }
        top++;
        db[top]=key;
        cache[key]=value;

    }
    int get(int k)
    {
        if(cache[k]==-1)
        {
            return -1;
        }
        
        return cache[k];
    }
    void print()
    {
        if(top>-1)
        {
             for(int i=top; i >=0; i--)
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
        val=v;
        key=k;
        left=NULL;
        right=NULL;
    }
};

class LRU
{
    public:
    Node *dbPointer[10001];
    int db_size;
    int cache[10001];
    Node *front;
    Node *rear;
    int capacity;
    int curr;
    LRU(int n)
    {
        capacity=n;
        curr=0;
        for(int i=0; i< 10001; i++)
        {
            cache[i]=-1;
        }
        front=NULL;
        rear=NULL;
    }
    int get(int k)
    {
        if(cache[k]==-1)
        {
            return -1;
        }
        Node *t=dbPointer[k];
        //when we get, we evict and then add it to the back
        put(k, t->val);
        return cache[k];
    }
    void put(int key, int val)
    {
        if(curr==capacity)
        {
            front=front->right;
            cache[key]=-1;
            Node *newNode=new Node(key, val);
            newNode->left=rear;
            rear=newNode;
            dbPointer[key]=newNode;            
            return;
        }
        if(curr==0)
        {
            Node *newNode=new Node(key, val);
            cache[key]=val;
            front=newNode;
            rear=newNode;
            curr++;
            return;
        }
        Node *newNode= new Node(key, val);
        cache[key]=val;
        newNode->left=rear;
        rear=newNode;
        dbPointer[key]=newNode;
        curr++;
    }
    
    void print()
    {
        Node *t=rear;
        while(t!=NULL)
        {
            cout << t->key << " ";
            t=t->left;
        }
        cout << endl;
    }
};



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string inp="";
    LIFO lifo=LIFO(0);
    LRU lru= LRU(0);
    string cat="";
    while(inp != "done")
    {  
        
        cin>> inp;
        if(inp=="LIFO")
        {
            cat="LIFO";
            int size;
            cin >> size;
            lifo=LIFO(size);
        }
        if(inp=="put" && cat=="LIFO")
            {
                int k ,val;
                cin >> k >> val;
                lifo.put(k,val);
            }
        if(inp=="get" && cat=="LIFO")
                {
                    int val;
                    cin >> val;
                    cout << lifo.get(val) << endl;
            }
            if(inp == "done")
            {
                break;
            }
            
                if(inp=="print" && cat=="LIFO")
                {
                    lifo.print();
            }
            if(inp == "LRU")
            {
                cat="LRU";
                int size;
                cin >> size;
                lru=LRU(size);
            }
       
        if(inp=="put" && cat=="LRU")
            {
                int k ,val;
                cin >> k >> val;
                lru.put(k,val);
            }
        if(inp=="get" && cat=="LRU")
                {
                    int val;
                    cin >> val;
                    cout << lru.get(val) << endl;
            
            }
            if(inp == "done")
            {
                break;
            }
            
                if(inp=="print" && cat=="LRU")
                {
                    lru.print();
            }
        
        
    }
    
        
        
    
    return 0;
}
