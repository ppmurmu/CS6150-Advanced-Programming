#include <iostream>
#include <string>
using namespace std;
//
//  zoo-week02.h
//  week02
//
//  Created by John Augustine on 11/08/2024.
//

#ifndef zoo_week02_h
#define zoo_week02_h

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

int main()
{

    return 0;
}
