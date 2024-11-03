#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(vector<vector<int>> &adjMatrix)
{
    // pair consist of <distance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(5, INT_MAX);

    // assuming 0 is source
    dist[0] = 0;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for (int i = 0; i < 5; i++)
        {
            if (adjMatrix[node][i] > 0 && dis + adjMatrix[node][i] < dist[i])
            {
                dist[i] = dis + adjMatrix[node][i];
                pq.push({dist[i], i});
            }
        }
    }

    for (int i = 1; i < 5; i++)
    {
        cout << i << " distance " << dist[i] << endl;
    }
}

void dijk(vector<vector<int>> adj)
{
    int n = adj.size();
    // distance, node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);
    int total = 0;
    pq.push({0, 0});

    dist[0] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (int i = 0; i < n; i++)
        {

            if (adj[node][i] > 0 && adj[node][i] + d < dist[i])
            {
                dist[i] = adj[node][i] + d;
                pq.push({dist[i], i});
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    vector<vector<int>> adjMatrix(5, std::vector<int>(5, 0));

    // Adding edges to the graph (adjacency matrix)
    adjMatrix[0][1] = 10;
    adjMatrix[0][4] = 3;
    adjMatrix[1][2] = 2;
    adjMatrix[1][4] = 4;
    adjMatrix[2][3] = 9;
    adjMatrix[3][2] = 7;
    adjMatrix[4][1] = 1;
    adjMatrix[4][2] = 8;
    adjMatrix[4][3] = 2;

    dijk(adjMatrix);
    dijkstra(adjMatrix);

    return 0;
}