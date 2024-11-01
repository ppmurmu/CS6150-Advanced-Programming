#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj,
             int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}
void dfs(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), false);

    stack<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {

                q.push(adj[u][i]);
                visited[adj[u][i]] = true;
            }
        }
    }
}
void bfs(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), false);

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {

                q.push(adj[u][i]);
                visited[adj[u][i]] = true;
            }
        }
    }
}
int main()
{
    // Number of vertices in the graph
    int V = 8;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V, vector<int>(V, 0));

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);

    return 0;
}