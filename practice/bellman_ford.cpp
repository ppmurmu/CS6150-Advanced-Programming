#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void bellmanFord(vector<vector<int>> &edges, int V)
{
    vector<int> dist(V, INT_MAX);

    dist[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }

    cout << "------Shortest path " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " distance " << dist[i] << endl;
    }
}
int main()
{
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};
    bellmanFord(edges, 6);
    return 0;
}