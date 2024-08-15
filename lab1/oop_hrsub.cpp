//
//  givenclasses.h
//  week01-shape-inventory
//
//  Created by John Augustine on 04/08/2024.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef givenclasses_h
#define givenclasses_h

class Polygon
{ // this is an abstract class. Why?
private:
    string name;

public:
    Polygon(string name);
    virtual ~Polygon() {}
    string getName();
    virtual double getArea() = 0; // pure virtual function
    virtual double getCircumference() = 0;
    virtual void print() = 0;
    bool isBiggerByArea(Polygon &p);
    bool isBiggerByCircumference(Polygon &p);
};

class RightTriangle : public Polygon
{
protected:
    double base;
    double height;

public:
    RightTriangle(string name, double base, double height);
    ~RightTriangle() {}
    double getArea();
    double getCircumference();
    void print();
};

class Rectangle : public Polygon
{
protected:
    double base;
    double height;

public:
    Rectangle(string name, double base, double height);
    ~Rectangle() {}
    double getArea();
    double getCircumference();
    void print();
};

class Square : public Rectangle
{
public:
    Square(string name, double side);
    ~Square() {}
    void print();
};

class Node
{
private:
    Polygon *p;
    Node *next;

public:
    Node(Polygon *p)
    {
        this->p = p;
        next = NULL;
    }
    Node *getNext() { return next; }
    Polygon *getPolygonPtr() { return p; }
    void setNext(Node *nxt) { next = nxt; }
    void updatePointer(Node *nxt) { next = nxt; }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() { head = NULL; }
    bool addNode(Polygon *p); // Must be an O(1) time operation
    bool deleteNode(string nme);
    void print();
    double getTotalArea();
    double getTotalCircumference();
};

#endif /* givenclasses_h */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//----------------polygon--------------------

Polygon::Polygon(string name) : name(name) {};

string Polygon::getName()
{
    return this->name;
}
bool Polygon::isBiggerByArea(Polygon &p)
{
    return this->getArea() > p.getArea();
}

bool Polygon::isBiggerByCircumference(Polygon &p)
{
    return this->getCircumference() > p.getCircumference();
}

//----------------right triangle--------------------

RightTriangle ::RightTriangle(string name, double base, double height) : Polygon(name),
                                                                         base(base), height(height) {};

double RightTriangle ::getArea()
{
    return 0.5 * base * height;
}

double RightTriangle::getCircumference()
{
    return sqrt(base * base + height * height) + base + height;
}

void RightTriangle::print()
{
    printf("right-triangle %s %.2f %.2f\n", this->getName().c_str(), base, height);
}

//----------------rectangle--------------------

Rectangle::Rectangle(string name, double base, double height) : Polygon(name), base(base), height(height) {};

double Rectangle ::getArea()
{
    return base * height;
}

double Rectangle::getCircumference()
{
    return 2.0 * (base + height);
}

void Rectangle::print()
{
    printf("rectangle %s %.2f %.2f\n", this->getName().c_str(), base, height);
}

//----------------square--------------------

Square ::Square(string name, double side) : Rectangle(name, side, side) {};

void Square::print()
{
    printf("square %s %.2f\n", this->getName().c_str(), base);
}

//----------------LinkedList--------------------

bool LinkedList ::addNode(Polygon *p)
{
    Node *n = new Node(p);
    n->setNext(head);
    head = n;
    return true;
}

bool LinkedList::deleteNode(string nme)
{

    if (head == NULL)
    {
        return true;
    }

    // if head is nme
    if (head->getPolygonPtr()->getName() == nme)
    {
        Node *temp = head;
        head = head->getNext();
        free(temp->getPolygonPtr());
        free(temp);
        return true;
    }

    Node *n = head;
    while (n->getNext() != NULL)
    {
        if (n->getNext()->getPolygonPtr()->getName() == nme)
        {
            Node *temp = n->getNext();
            n->setNext(temp->getNext());
            free(temp);
            return true;
        }
    }

    return false;
}

void LinkedList::print()
{
    Node *n = head;
    while (n != NULL)
    {
        Polygon *temp = n->getPolygonPtr();
        temp->print();
        n = n->getNext();
    }
}

double LinkedList::getTotalArea()
{
    double sum = 0;
    Node *itr = head;
    while (itr != NULL)
    {
        sum += itr->getPolygonPtr()->getArea();
        itr = itr->getNext();
    }
    return round(sum * 100.0) / 100;
}

double LinkedList::getTotalCircumference()
{
    double sum = 0;
    Node *itr = head;
    while (itr != NULL)
    {
        sum += itr->getPolygonPtr()->getCircumference();
        itr = itr->getNext();
    }
    return round(sum * 100.0) / 100;
}

//----------------main--------------------

int main()
{
    LinkedList inv;
    string inp = "";
    while (inp != "done")
    {
        cin >> inp;
        if (inp == "add")
        {
            string type;
            cin >> type;
            if (type == "right-triangle")
            {
                string name;
                double base, height;
                cin >> name;
                cin >> base;
                cin >> height;
                inv.addNode(new RightTriangle(name, base, height));
            }
            if (type == "rectangle")
            {
                string name;
                double base, height;
                cin >> name;
                cin >> base;
                cin >> height;
                inv.addNode(new Rectangle(name, base, height));
            }
            if (type == "square")
            {
                string name;
                double side;
                cin >> name;
                cin >> side;
                inv.addNode(new Square(name, side));
            }
        }
        if (inp == "delete")
        {
            string name;
            cin >> name;
            inv.deleteNode(name);
        }
        if (inp == "print")
        {
            string printWhat;
            cin >> printWhat;
            if (printWhat == "circumference")
            {
                printf("%.2f\n", inv.getTotalCircumference());
            }
            if (printWhat == "area")
            {
                printf("%.2f\n", inv.getTotalArea());
            }
        }
        if (inp == "print-all")
        {
            inv.print();
        }
    }
    return 0;
}

/* end of your program */