#include <iostream>
#include <stack>

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

    void addEdge(int i, int j)
    {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }

    void dfs(int s)
    {
        bool vis[vertex];

        for (int i = 0; i < vertex; i++)
        {
            vis[i] = false;
        }

        stack<int> st;

        st.push(s);
        vis[s] = true;
        while (!st.empty())
        {
            int curr = st.top();
            cout << curr << " ";
            st.pop();

            for (int i = 0; i < vertex; i++)
            {
                if (!vis[i] && adj[curr][i])
                {
                    st.push(i);
                    vis[i] = true;
                }
            }
        }
    }
};
int main()
{
    Graph g = Graph(5);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.dfs(2);
    // g.display();
    return 0;
}