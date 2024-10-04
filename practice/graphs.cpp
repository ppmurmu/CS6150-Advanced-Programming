#include <iostream>
using namespace std;

class Graph
{
public:
    int vertex;
    int **adj;
    Graph(int v)
    {
        adj = new int *[v];
        vertex = v;
        for (int i = 0; i < v; i++)
        {
            adj[i] = new int[v];
            // Initialize all values to 0 (no edges)
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g = Graph(5);

    g.display();
    return 0;
}