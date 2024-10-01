#include<iostream>
#include<string>
#include<time.h>
#include<random>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
    Node(int v)
    {
        val=v;
        next=NULL;
    }
};
class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
    void add(int n)
    {
        Node *newNode=new Node(n);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    //count the length of the linkedList
    int lengthOfLL()
    {
        int c=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        return c;

    }
    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<< temp->val << " ";
            temp=temp->next;
        }
        cout<< endl;
    }
};

LinkedList adj[100];

double randomGenerate()
{
    //const int MAXRAND=1000000;
    //sand(time(0));
    //double r=random()%MAXRAND;
    //return ((double)rand())/ RAND_MAX ; //r/MAXRAND;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0,1.0);
    return dis(gen);
}


// function to generate a random integer <b
int randomGenerateLimit(int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0,1);
    int t=(dis(gen) * 100);
    int t2 = t%b ;
    return t2;
}

void createGraph(int n, double p)
{ 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double t=randomGenerate();
            if(t<= p)
            {
                adj[i].add(j);
                adj[j].add(i);
            }
        }
    }
}
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<< "Node "<<i<<" :";
        adj[i].print() ;
    }
}
void printStatistics(int n)
{
    int minD=1000;
    int maxD=-1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int curr=adj[i].lengthOfLL();
        if(curr<minD)
        {
            minD=curr;
        }
        if(curr>maxD)
        {
            maxD=curr;
        }
        sum+=curr;
    }
    double avg=sum/n;
    cout<< "Avg degree is "<< avg << endl;
    cout<<"Min degree is "<< minD << endl;
    cout<<"Max degree is "<<maxD << endl;

}

int getRandomNeighbour(int i)
{
    Node *temp=adj[i].head;
    //when node has no neighbours
    if(temp==NULL)
    {
        return -1;
    }
    //get the degree of each node (also equal to the length of the linkedlist)
    int deg=adj[i].lengthOfLL();
    int r=randomGenerateLimit(deg);
    int c=-1; //count the index
        
        while(temp!=NULL)
        {
            c++;
            if(c==r)
            {
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
}

void gossip(int n, int s)
{
    int day=1;
    bool visited[n];

    int res[n]; //to store nodes that know gossip
    int resCount=0; //to keep the count of nodes that know gossip
    int resIndex=0; //index to keep track of new nodes that know gossip
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    //store the source
    res[0]=s;
    resCount++; //because the source knows
    resIndex++;
    cout << "Day " << day << " : " << res[0] << " ";
    visited[s]=true;
    while(true)
    {
        int c=0; //to keep track of change in resCount after each day
        for(int i=0; i < resCount;i++)
        {
            int t=getRandomNeighbour(res[i]);
            if(t!=-1)
            {
                if(visited[t]==false)
                {
                    res[resIndex]=t;
                    c++;
                    resIndex++;
                    visited[t]=true;
                    
                }
                //visited[t]=true;
            }
        }
       

        if(c!=0)
        {
            resCount+=c;
            for(int i=0;i< resCount;i++)
            {
                cout<< res[i] << " ";
            }
            
        }
        else
        {
            break;
            //no new nodes got the gossip
        }
        cout << endl;
        day++;
        cout<< "Day "<< day << " : ";
        if(resCount==n)
        {
            break;
        }
    }

}


int main(){
    string cmd="";
    int n;
    double p;
    while(cmd!="done")
    {
        cin>>cmd;
        if(cmd=="graph")
        {
           
            cin>>n;
            cin>>p;
            createGraph(n,p);

        }
        if(cmd=="print")
        {
            print(n);
            printStatistics(n);

        }
        if(cmd=="gossip")
        {
            int s;
            cin>>s;
            gossip(n,s);

        }
    }
    return 0;
}