#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void insert(int val)
    {
        Node *newNode = new Node(val);
        Node *curr = root;
        Node *temp;
        while (curr != NULL)
        {
            temp = curr;
            if (val > curr->val)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (temp == NULL)
        {
            // root is empty
            root = newNode;
            return;
        }
        if (val > temp->val)
        {
            // make it the right node
            temp->right = newNode;
        }
        else
        {
            temp->left = newNode;
        }
    }
    void print(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
    void remove(int val)
    {
        // iterative
        Node *curr = root;
        Node *temp;
        while (curr != NULL)
        {
            temp = curr;
            if (val > curr->val)
            {
                // towards right
                curr = curr->right;
            }
            else if (val < curr->val)
            {
                // toward left
                curr = curr->left;
            }
        }
        if (curr == NULL)
        {
            // val not found
            cout << "not found";
            return;
        }
        if (curr->left == NULL && curr->right == NULL)
        {
            //
        }
    }
};

int main()
{
    BST tree = BST();
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.print(tree.root);
}
