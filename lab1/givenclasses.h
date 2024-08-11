//
//  givenclasses.h
//  week01-shape-inventory
//
//  Created by John Augustine on 04/08/2024.
//

#ifndef givenclasses_h
#define givenclasses_h
#include<string>
using namespace std;

class Polygon { // this is an abstract class. Why?
private:
    string name;
public:
    Polygon(string name);
    virtual ~Polygon(){}
    string getName();
    virtual double getArea() = 0; // pure virtual function
    virtual double getCircumference() = 0;
    virtual void print() = 0;
    bool isBiggerByArea(Polygon & p);
    bool isBiggerByCircumference(Polygon & p);
};

class RightTriangle : public Polygon {
protected:
    double base;
    double height;
public:
    RightTriangle(string name, double base, double height);
    ~RightTriangle(){}
    double getArea();
    double getCircumference();
    void print();
};

class Rectangle : public Polygon {
protected:
    double base;
    double height;
public:
    Rectangle(string name, double base, double height);
    ~Rectangle(){}
    double getArea();
    double getCircumference();
    void print();
};

class Square: public Rectangle {
public:
    Square(string name, double side);
    ~Square(){}
    void print();
};


class Node {
private:
    Polygon *p;
    Node * next;
public:
    Node(Polygon * p) { this->p = p; next = NULL;}
    Node * getNext() {return next;}
    Polygon * getPolygonPtr(){return p;}
    void setNext(Node * nxt){next = nxt;}
    void updatePointer(Node * nxt){next = nxt;}
};


class LinkedList {
private:
    Node * head;
public:
    LinkedList(){ head = NULL;}
    bool addNode(Polygon * p); // Must be an O(1) time operation
    bool deleteNode(string nme);
    void print();
    double getTotalArea();
    double getTotalCircumference();
};

#endif /* givenclasses_h */
