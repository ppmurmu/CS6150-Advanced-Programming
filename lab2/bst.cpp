#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

public:
    Node(int k)
    {
        val = k;
        left = right = NULL;
    }
};

class BST
{
}