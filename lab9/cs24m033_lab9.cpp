#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

double graph[2001][2001];




//int minDistance(int dist[], bool sptSet[])
//{

//     int min = 1000000, min_index;
//     for (int v = 0; v < V; v++)
//         if (sptSet[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;

//     return min_index;
//}





void BFS(int s, int n)
{
    int res[n][n];
    //intialize res
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            res[i][j]=0;
        }
    }
    queue<int> q;
    q.push(s);
    bool visited[n];
    for(int i=0; i< n; i++)
    {
        visited[i]=false;
    }
    visited[s]=true;
    double sum=0;
    while(q.empty() != true)
    {
        int t=q.front();
        q.pop();
        for(int i=0; i< n ;i++)
        {
            if(visited[i]==false && graph[t][i]!=0)
            {
                //cout << i << " ";
                q.push(i);
                visited[i]=true;
                res[t][i]=1;
                res[i][t]=1;
                sum+=graph[t][i];
            }
        }
    }
    //show output
    
    for(int i=0;i< n; i++)
    {
        cout << i << " ";
        for(int j=0; j< n; j++)
        {
            if(res[i][j]!=0)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout <<"total_weight = " << fixed << sum ;
}



int findSmallestVertex(int key[], bool visited[], int n)
{
    // Initialize min value
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n)
{
    int parent[n];
    int res[n][n];
    int key[n];
    
    bool visited[n];
    double sum=0;
    // Initialize
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX ; 
        visited[i] = false;
        for(int j=0; j< n; j++)
        {
            res[i][j]=0;
        }
    }
    key[0] = 0;

    //root 
    parent[0] = -1;

    //MST has n-1 vertex
    for (int count = 0; count < n - 1; count++)
    {
        int u = findSmallestVertex(key, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {

            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        res[i][parent[i]]=1;
        res[parent[i]][i]=1;
    }

    
    for(int i=0;i<n;i++)
    {
        cout << i << " ";
        for(int j=0;j<n;j++)
        {
            if(res[i][j]!=0)
            {
                cout << j << " ";
                        sum+=res[i][parent[i]];

            }
        }
        cout << endl;
    }
    cout << fixed << "total_weight : " << sum << endl;
}




void print(int n)
{
    for(int i=0;i< n ;i++)
    {
        for(int j=0; j< n ; j++)
        {
            cout << fixed << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string cmd="";
    int i=0; //length of graph list
    //initialize graph
    for(int i=0;i<2001; i++)
    {
        for(int j=0;j< 2001;j++)
        {
            graph[i][j]=0;
        }
    }
    
    while(cmd!="done")
    {
        if(cmd!="Node")
        {
            cin >> cmd;

        }
        if(cmd == "Node")
        {
            int u;
            cin >> u;
            i++;
            string t1="", t2="";
            
            while(t1!="Node" && t1!= "BFS" && t1!="SSSP" && t1!= "MST")
            {
                cin>>t1;
                if(t1=="Node" || t1== "BFS" || t1=="SSSP" || t1=="MST" )
                {
                    cmd =t1;
                     break;
                  }
                cin>>t2;
                
                int v= stoi(t1);
                double w= stod(t2);                
                graph[u][v]=w;
            }
            
        }
        
        if(cmd=="BFS")
        {
            int s;
            cin >> s;
            BFS(s, i);
        }
        if(cmd=="MST")
        {
            primMST(i);
        }
        
        
    }
    
    return 0;
}
