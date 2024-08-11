#include "givenclasses.h"
#include <math.h>
#include <iostream>
using namespace std;

// Polygon::Polygon(string name){
//     this->name=name;
// }

Polygon::Polygon(string name) : name(name) {};

string Polygon::getName(){
    return this->name;
}




RightTriangle :: RightTriangle(string name, double base, double height) : 
Polygon(name),
base(base), height(height) {};

double RightTriangle :: getArea(){
    return 0.5*base*height;
}

double RightTriangle::getCircumference(){
    return sqrt(base*base + height*height) + base+ height;
}

void RightTriangle::print(){
    cout << "Right-Triangle " << this->getName() << " " << base << " " << height << endl;
     

}

Rectangle::Rectangle(string name, double base, double height) : 
Polygon(name), base(base), height(height) {};

double Rectangle :: getArea(){
    return base*height;
}

double Rectangle::getCircumference(){
    return 2*(base+height);
}

void Rectangle::print(){
    cout << "Rectangle " << this->getName() << " " << base << " " << height << endl;

}

Square :: Square(string name, double side): Rectangle(name, side, side) {};

void Square::print(){
        cout << "Square " << this->getName() <<" " << base << endl;


}


bool LinkedList :: addNode(Polygon * p) {
   Node* n=new Node(p);
   n->setNext(head);
   head=n;
   return true;
}

bool LinkedList:: deleteNode(string nme){

     if(head==NULL)
    {   
    	    return true;
     }
    
    //if head is nme
    if(head->getPolygonPtr()->getName() == nme)
    {
    	Node *temp=head;
    	head=head->getNext();
    	free(temp->getPolygonPtr());
    	free(temp);
    	return true;
    }
    
    Node *n=head;
    while(n->getNext() != NULL)
    {
    	if(n->getNext()->getPolygonPtr()->getName() == nme)
    	{
    		Node *temp=n->getNext();
    		n->setNext(temp->getNext());
    		free(temp);
    		return true;
    		
    	}
    }
    
    return false;
     
 

}

double LinkedList::getTotalArea(){
    double sum=0;
    Node* itr=head;
    while(itr!=NULL)
    {
        sum+= itr->getPolygonPtr()->getArea();
        itr= itr->getNext();
    }
    return sum;
}

double LinkedList::getTotalCircumference(){
    double sum=0;
    Node* itr=head;
    while(itr!=NULL)
    {
        sum+= itr->getPolygonPtr()->getCircumference();
        itr= itr->getNext();
    }
    return sum;
}








int main(){
    LinkedList inv;
    string inp="";
    while(inp!="done")
    {
        cin >> inp;
        if(inp == "add")
        {
            string type;
            cin >>type;
            if(type== "right-triangle")
            {
                string name;
                double base, height;
                cin >> name ;
                cin >> base;
                cin >> height;
                inv.addNode(new RightTriangle( name,  base,  height));
            }
            if(type== "rectangle")
            {
                string name;
                double base, height;
                cin >> name ;
                cin >> base;
                cin >> height;
                inv.addNode(new Rectangle( name,  base,  height));
            }
            if(type== "square")
            {
                string name;
                double side;
                cin >> name;
                cin >> side;
                inv.addNode(new Square(name, side));

            }
           


        }
        if(inp == "delete") 
        {
        	string name;
        	cin >> name;
        	inv.deleteNode(name);

        }
        if(inp == "print")
        {
            string printWhat;
            cin >> printWhat;
            if(printWhat == "circumference")
            {
                cout << inv.getTotalCircumference()  << " ";
            }
            if(printWhat == "area")
            {
                cout << inv.getTotalArea()  << " ";

            }
        }
        
    }
    return 0;
}
