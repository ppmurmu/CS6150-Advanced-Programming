#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMin(vector<vector<int>> &graph, vector<int> &key, vector<bool> &mstSet)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < key.size(); i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void print(int V, vector<int> &parent, vector<vector<int>> &graph)
{
    for (int i = 1; i < V; i++)
    {
        cout << i << "-->" << parent[i] << " weight= " << graph[i][parent[i]] << endl;
    }
}

void prims(int V, vector<vector<int>> &graph)
{

    vector<int> parent(V);  // to store mst
    vector<bool> mstSet(V); // keep check of unvisited vertices
    vector<int> key(V);
    // intialize the
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; // first vertex is added to the mst

    for (int count = 0; count < V - 1; count++)
    {
        int u = getMin(graph, key, mstSet);
        mstSet[u] = true;
        for (int i = 0; i < V; i++)
        {
            if (graph[u][i] > 0 && mstSet[i] == false && graph[u][i] < key[i])
            {
                key[i] = graph[u][i];
                parent[i] = u;
            }
        }
    }
    print(V, parent, graph);
}

int main()
{
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};
    prims(5, graph);
    return 0;
}