#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void print(double d){
    cout << fixed << setprecision(5) << d << endl;
      return;
}

/******* Do Not Edit Above This Line. No other headers allowed. *********/

string name[1000];
string animal[1000];
int weight[1000];

//fn to calculate mean
double findMean(string anim)
{
    int i=0;
    int sum=0,c=0;
    while(animal[i]!="done")
    {
        if(animal[i]==anim)
        {
            sum+=weight[i];
            c++;
        }
        i++;
    }
    double mean=sum*1.0 / c;
    return mean;
}


//fn to calculate standard deviation
double findSD(string anim)
{
    double mean=findMean(anim);
    int i=0;
    int sum=0;
    while(animal[i]!="done")
    {
        if(animal[i]==anim)
        {
            sum+=sqrt(pow(weight[i] - mean, 2));
        }
        i++;
    }

    return sum;
}

double findMode(string anim)
{
    int temp[1000];
    int i=0,j=0;
    while(animal[i]!="done")
    {
        if(animal[i]==anim)
        {
            temp[j]= weight[i];
            j++;
        }
        i++;
    }
    // for(int i=0; i< j; i++)
    // {
    //     cout << temp[i];
    // }
    //sort the temp
    for(int k=0; k< j ;k++)
    {
        for(int l=0; l<j-1;l++)
        {
            if(temp[l]> temp[l+1])
            {
                int t=temp[l];
                temp[l]=temp[l+1];
                temp[l+1]=t;
            }
        }
    }
    
    
    
    int mode=0, c=1, maxi=0;
    for(int k=0; k < j-1 ;k++)
    {
        if(temp[k+1]==temp[k])
        {
            c++;
        }
        else
        {
            if(c>maxi)
            {
                maxi=c;
                mode=temp[k];
                c=1;
            }
            
        }
        
    }
    return mode;
    
}

double findMedian(string anim)
{
    int temp[1000];
    int i=0,j=0;
    while(animal[i]!="done")
    {
        if(animal[i]==anim)
        {
            temp[j]= weight[i];
            j++;
        }
        i++;
    }
    //sort the temp
    for(int k=0; k< j ;k++)
    {
        for(int l=0; l<j-1; l++)
        {
            if(temp[l]> temp[l+1])
            {
                int t=temp[l];
                temp[l]=temp[l+1];
                temp[l+1]=t;
            }
        }
    }
    
    if(j%2==1)
    {
        return temp[j/2];
        
    }
    else
    {
     return (temp[(j/2)-1] + temp[j/2])/2;
    }
    
    
}

double findFact(int n)
{
    int p=1;
    for(int i=n; i>=1;i--)
    {
        p*=i;
    }
    return p;
}

double findProb(int n, int p, int c)
{
    double t1= findFact(n) / (findFact(c) * findFact(n-c));
    double t2= pow(p, c);
    double t3= pow(1-p, n-c);
    return t1*t2*t3;
    
}

double findFinalProb(string anim, double val, double p)
{
    int i=0,c=0, n=0;
    while(animal[i]!="done")
    {
        if(animal[i]==anim)
        {
            if(weight[i] < val)
            {
                c++;
            }
            n++;
        }
        i++;
    }
    
    
    
    return findProb(n, p, c);
    
}


int main() {
    /* Enter your code here. Read input using cin. Print output using the print function above. */ 
    int i=0;
    string inp="";
    cin >> inp;
    while(inp!="done")
    {
        string a=inp;
        string n;
        cin >> n;
        int w;
        cin >>w;
        animal[i]= a;
        name[i]=n;
        weight[i]=w;
        i++;
        cin >> inp;
    }
    animal[i]="done";
    name[i]= "done";
    weight[i]= 0;
    
    string cmd;
    cin >> cmd;
    if(cmd == "mean")
    {
        string a;
        cin >> a;
        cout << fixed << setprecision(5) <<  findMean(a); 
    }
    if( cmd == "mode")
    {
         string a;
        cin >> a;
        
       cout <<  findMode(a); 
        
    }
    if(cmd == "stddev")
    {
        string a;
        cin >> a;
        cout << fixed << setprecision(5) <<  findSD(a); 
        
    }
    if(cmd == "median")
    {
        string a;
        cin >> a;
        cout << fixed << setprecision(5) <<  findMedian(a); 
    }
    
    if(cmd == "probability")
    {
        string a;
        cin>>a;
        int val;
        cin>>val;
        double p;
        cin >> p;
        cout << fixed << setprecision(5) << findFinalProb(a, val, p); 
        
        
    }
    
    
   
     
    
    return 0;
}

//undefined
