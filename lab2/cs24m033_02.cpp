//
//  zoo-week02.h
//  week02
//
//  Created by John Augustine on 11/08/2024.
//

#ifndef zoo_week02_h
#define zoo_week02_h

#include <iostream>
#include <string>
using namespace std;
const double error = 0.0000001;

class Animal
{ // this is an abstract class. Why?
protected:
    string name;
    double weight;

public:
    Animal(string nm, double wt);
    virtual ~Animal() {}
    string getName() { return name; }
    double getWeight() { return weight; }
    virtual string getType() = 0;
    virtual string getSpecies() = 0;
    virtual void print() = 0;
};

class Type : public Animal
{
protected:
    string type; /* Either bird or mammal */
public:
    Type(string nm, double wt, string tp);
    ~Type() {}
    string getType() { return type; }
    virtual string getSpecies() = 0;
    virtual void print() = 0;
};

class Species : public Type
{
protected:
    string species;

public:
    Species(string nm, double wt, string tp, string sp);
    ~Species() {}
    string getSpecies() { return species; }
    void print()
    {
        cout << "I am a " << species << " namded " << name << " and I am a " << type << ". I weigh " << weight << " KGs.\n";
    }
};

class Node
{
private:
    Animal *a;
    Node *left, *right, *parent;
    bool bLeft; /* true when left child.
                 false when right child.
                 Don't care when root. */
public:
    Node(Animal *a);
    ~Node();
    Node *getLeft() { return left; }
    Node *getRight() { return right; }
    Node *getParent() { return parent; }
    Animal *getAnimalPtr() { return a; }
    void setLeft(Node *lft) { left = lft; }
    void setRight(Node *rgt) { right = rgt; }
    void setParent(Node *pnt) { parent = pnt; }
    void setLeft() { bLeft = true; }
    void setRight() { bLeft = false; }
};

class BST
{
    /*
     Implement a BST of Nodes with animals as content. The BST key must be the weight of the animals. Thus, all animals in the left sub tree of an animal must be lighter while those on the right sub tree must not be lighter.
     */
private:
    Node *root;
    Node *search(Node *nd, string nm); // similar to search(string nm) but with pointer made explicit to facilitate recursive search.

    Node *findInorderSuccessor(Node *nd); // return the inorder successor node pointer to nd. Return NULL if no such successor. This is used in deleteNode() and in getTotalWeightInRange.

public:
    BST() { root = NULL; }

    bool isEmpty(); // self-explanatory

    Node *search(double wt); // return an animal (Node pointer) whose weight is between wt-error and wt-error; return NULL if no such Animal exists.

    Node *search(string nm); // use search(Node*, string)

    bool addNode(Animal *a); // self-explanatory

    bool deleteNode(string nme); // self-explanatory. Make sure to release the memory. Use findInorderSuccessor.

    double getTotalWeightInRange(double low, double hi);
    /*
     The above function must find and traverse the range of animals in the weight range low to high and return their total weight.
     */

    double getTotalWeightInRange(double low, double hi, string species);
    /*
     Same as the previous function of the same name, but must only return the total weight of the given species in the weight range low to hi. If the species is the empty string, then all animals in the range must be considered. findInorderSuccessor
     */
};

#endif /* zoo_week02_h */

Animal::Animal(string nm, double wt)
{
    this->name = nm;
    this->weight = wt;
}

// Animal::Animal(string nm, double wt) : name(nm) , weight(wt) {}

Type::Type(string nm, double wt, string tp) : Animal(nm, wt)
{
    type = tp;
}

Species::Species(string nm, double wt, string tp, string sp) : Type(nm, wt, tp)
{
    species = sp;
}

Node::Node(Animal *a)
{
    this->a = a;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->bLeft = false;
}
Node::~Node()
{
}
//-----------------------BST implementation---------------------
bool BST::isEmpty() // self-explanatory
{
    return root == NULL;
}

Node *BST::search(Node *n, string nm)
{
    if (n == NULL)
    {
        return NULL;
    }
    Node *left = search(n->getLeft(), nm);
    if (left != NULL)
    {
        return left;
    }
    if (n->getAnimalPtr()->getName() == nm)
    {
        return n;
    }
    return search(n->getRight(), nm);
}

Node *BST::findInorderSuccessor(Node *nd)
{
    if (nd == NULL)
        return NULL;

    if (nd->getRight() != NULL)
    {
        Node *curr = nd->getRight();
        while (curr->getLeft() != NULL)
        {
            curr = curr->getLeft();
        }
        return curr;
    }
    Node *parent = nd->getParent();
    while (parent != NULL && nd == parent->getRight())
    {
        nd = parent;
        parent = parent->getParent();
    }
    return parent;
}
Node *BST::search(double wt)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *curr = root;

    while (curr != NULL)
    {
        if (wt > curr->getAnimalPtr()->getWeight())
        {
            curr = curr->getRight();
        }
        else if (wt < curr->getAnimalPtr()->getWeight())
        {
            curr = curr->getLeft();
        }
        else
        {
            return curr;
        }
    }

    return NULL;
}

Node *BST::search(string nm) // use search(Node*, string)
{
    return search(root, nm);
}

bool BST::addNode(Animal *a)
{
    Node *temp = new Node(a);
    if (root == NULL)
    {
        root = temp;
        return true;
    }
    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (a->getWeight() < curr->getAnimalPtr()->getWeight())
        {
            curr = curr->getLeft();
        }
        else
        {
            curr = curr->getRight();
        }
    }
    temp->setParent(parent);
    if (a->getWeight() < parent->getAnimalPtr()->getWeight())
    {
        parent->setLeft(temp);
    }
    else
    {
        parent->setRight(temp);
    }
    return true;
}

bool BST::deleteNode(string nme)
{
    Node *temp = search(nme);
    if (temp == NULL)
    {
        return false;
    }
    return true;
}
// total count of animals withing the range of the wieghts
double BST::getTotalWeightInRange(double low, double hi)
{
    Node *curr = root;
    double res = 0;

    while (curr != NULL)
    {

        if (curr->getAnimalPtr()->getWeight() >= low && curr->getAnimalPtr()->getWeight() <= hi)
        {
            res++;
        }
        curr = findInorderSuccessor(curr);
    }

    return res;
}

double BST::getTotalWeightInRange(double low, double hi, string species)
{
    Node *curr = root;
    double res = 0;

    while (curr != NULL)
    {
        if (curr->getAnimalPtr()->getSpecies() == species && curr->getAnimalPtr()->getWeight() >= low && curr->getAnimalPtr()->getWeight() <= hi)
        {
            res++;
        }
        curr = findInorderSuccessor(curr);
    }
    return res;
}

int main()
{
    BST zoo = BST();
    string query = "";
    while (true)
    {
        cin >> query;
        if (query == "birth")
        {
            // add
            string type, name, specie;
            double wt;
            cin >> type;
            cin >> name;
            cin >> wt;
            if (type == "tiger" || type == "monkey")
            {
                specie = "mammal";
            }
            else
            {
                specie = "bird";
            }
            Animal *a = new Species(name, wt, type, specie);
            zoo.addNode(a);
        }
        if (query == "death")
        {
            // death
            string name;
            cin >> name;
        }

        if (query == "query")
        {
            double a, b;
            string fourthWord;

            cin >> a;
            cin >> b;
            cin >> fourthWord;
            if (fourthWord == "end-query")
            {

                cout << zoo.getTotalWeightInRange(a, b) << endl;
            }
            else
            {
                string fifthWord;
                cin >> fifthWord;

                // count in specie
                cout << zoo.getTotalWeightInRange(a, b, fourthWord) << endl;
            }
        }
    }
    return 0;
}
