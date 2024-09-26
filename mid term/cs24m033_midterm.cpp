#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
    int val;
    string name;
    Node *next;
    int withdrawn;
    Node(int v, string n)
    {
        name=n;
        val=v;
        next=NULL;
        withdrawn=0;
    }
    void setNext(Node *n)
    {
        next=n;
    }
   
};

//QUESTION-1
class LinkedList1
{
    public:
    Node *head;
    LinkedList1()
    {
        head=NULL;
    }
    //adding tail to head
    void addNode(int val, string name)
    {
        Node *newNode= new Node(val, name);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        if(val> head->val)
        {
            newNode->setNext(head);
            head=newNode;
        }
      
    }
    
};

//QUESTION-2





class LinkedList2
{
    public:
    Node *head;
    int highest;
    string highestName;
    LinkedList2()
    {
        head=NULL;
        highest=0;
    }
    void addNode(int val, string name)
    {
        Node *newNode= new Node(val, name);
        if(head==NULL)
        {
            head=newNode;
            highest=val;
            highestName=name;
            return;
        }
        newNode->setNext(head);
        head=newNode;
        //store the highest
        if(val>highest)
        {
            highest=val;
            highestName=name;
        }
       
    }
    void withdrawBid(string name)
    {
        //withdrawBid() will only affect when highest bid is of the withdrawer
        int tempHighestVal=0;
        string tempHighestName;
        
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->name == name)
            {
                curr->withdrawn=1;
            }
             curr=curr->next;

        }
        curr=head;
        while(curr!=NULL)
        {
            //reason for using >= is because my head is the last element that was added
            if(curr->withdrawn!=1 && curr->val >=tempHighestVal)
            {
                tempHighestVal=curr->val;
                tempHighestName=curr->name;
            }
            curr=curr->next;
        }
        highest=tempHighestVal;
        highestName=tempHighestName;
      
    }
};

//------------------------QUESTION-3--------------------------

class LinkedList3
{
    public:
    Node *head;
    Node *tail;
    int highest;
    string highestName;
    int secondHighest;
    string secondHighestName;
    LinkedList3()
    {
        head=NULL;
        highest=0;
    }
    void addNode(int val, string name)
    {
        Node *newNode= new Node(val, name);
        if(head==NULL)
        {
            head=newNode;
            highest=val;
            highestName=name;
            return;
        }
        

        newNode->setNext(head);
        head=newNode;
        
        //store the highest
        if(val>highest)
        {
            secondHighest=highest;
            secondHighestName=highestName;
            highest=val;
            highestName=name;
        }
        else if(val > secondHighest)
        {
            //edge  condition
            secondHighest=val;
            secondHighestName=name;
        }
       
    }
    void withdrawBid(string name)
    {
        int tempHighestVal=0;
        string tempHighestName;
        int tempSecondHighestVal=0;
        string tempSecondHighestName;
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->name == name)
            {
                curr->withdrawn=1;
            }
            curr=curr->next;

        }

        curr=head;
        while(curr!=NULL)
        {
            //reason for using >= is because my head is the last element that was added
            if(curr->withdrawn!=1 && curr->val >=tempHighestVal)
            {
                tempSecondHighestVal=tempHighestVal;
                tempSecondHighestName=tempHighestName;
                tempHighestVal=curr->val;
                tempHighestName=curr->name;
            }
            else if(curr->withdrawn!=1  && curr->val > secondHighest)
            {
                    tempSecondHighestVal=curr->val;
                    tempSecondHighestName=curr->name;
            }
            curr=curr->next;

        }
        highest=tempHighestVal;
        highestName=tempHighestName;
        secondHighest=tempSecondHighestVal;
        secondHighestName=tempSecondHighestName;
    }
};
//----QUESTION 4
class LinkedList4
{
    public:
    Node *head;
    Node *tail;
    int highest;
    string highestName;
    int secondHighest;
    string secondHighestName;
    int size;
    LinkedList4()
    {
        head=NULL;
        highest=0;
    }
    void addNode(int val, string name)
    {
        Node *newNode= new Node(val, name);
        size++;
        if(head==NULL)
        {
            head=newNode;
            highest=val;
            highestName=name;
            return;
        }

         //store in sorted way
        //val is greater than head than add it in front
        if(val>head->val)
        {
            newNode->setNext(head);
            head=newNode;
        }
        else if(val==head->val)
        {
            //keep going next until the first non equal
            Node *curr=head;
            Node *temp;
            while(curr!=NULL && val!=curr->val)
            {
                temp=curr;
                curr=curr->next;
            }
            temp->setNext(newNode);
            newNode->setNext(curr);
        }
        //val is less than head->val
        else{
            Node *curr=head;
            Node *temp;
           
            
        }
        
    }
    void withdrawBid(string name)
    {
        
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->name == name)
            {
                curr->withdrawn=1;
            }
            curr=curr->next;

        }

    
    }
};

int main()
{
    string cmd="";
    string type;
    LinkedList1 tradList=LinkedList1();
    LinkedList2 maxList=LinkedList2();
    LinkedList3 vickList=LinkedList3();
    LinkedList4 genList= LinkedList4();
    int k;


    while(cmd!="done")
    {
        cin >> cmd;
        //----------------------traditional----------------------------
        if(cmd=="traditional")
        {
            type="traditional";           
        }
        if(cmd=="bid" && type=="traditional")
        {
            string name; int val;
            cin >> name;
            cin >> val;
            tradList.addNode(val, name);
        }
        if(cmd=="done" && type=="traditional")
        {
            
                cout<< tradList.head->name << " " << tradList.head->val << endl;

            
        }
        
        
        //---------------------max-------------------------------------
        if(cmd=="max")
        {
            type="max";
        }
        if(cmd=="bid" && type=="max")
        {
            string name; int val;
            cin >> name;
            cin >> val;
            maxList.addNode(val, name);
        }
        if(cmd=="withdraw" && type=="max")
        {
            string name;
            cin >> name;
            
            maxList.withdrawBid( name);
        }
        if(cmd=="done" && type=="max")
        {
            //O(1) output for highest
            cout<< maxList.highestName << " " << maxList.highest << endl;
        }
        //-------------------------vickrey-----------------------
        if(cmd=="vickrey")
        {
            type="vickrey";
        }
        if(cmd=="bid" && type=="vickrey")
        {
            string name; int val;
            cin >> name;
            cin >> val;
            vickList.addNode(val, name);
        }
        if(cmd=="withdraw" && type=="vickrey")
        {
            string name;
            cin >> name;
            
            vickList.withdrawBid( name);
        }
        if(cmd=="done" && type=="vickrey")
        {
            //O(1) output for highest
            if(vickList.head==NULL || vickList.head->next ==NULL)
            {
                cout<< "incomplete"<<endl;

            }
            else
            {
                cout<< vickList.highestName << " " << vickList.secondHighest << endl;

            }
        }
        //---------generalized
        // if(cmd=="general")
        // {
        //     type="general";
        //     cin>>k;
        // }
        // if(cmd=="bid" && type=="general")
        // {
        //     string name; int val;
        //     cin >> name;
        //     cin >> val;
            
        // }
        // if(cmd=="withdraw" && type=="general")
        // {
        //     string name;
        //     cin >> name;
            
        //     vickList.withdrawBid( name);
        // }
        // if(cmd=="done" && type=="general")
        // {
        //     //O(1) output for highest
        //     if(genList.size< k)
        //     {
        //         cout<< "incomplete"<<endl;

        //     }
        //     else
        //     {
        //         cout<< vickList.highestName << " " << vickList.secondHighest << endl;

        //     }
        // }
        

    }   
    return 0;
}