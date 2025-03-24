#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;
int graph[4][4] = {{0, 3, INT_MAX, 7},
                   {8, 0, 2, INT_MAX},
                   {5, INT_MAX, 0, 1},
                   {2, INT_MAX, INT_MAX, 0}};

void fw()
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{

    // printGraph();
    fw();
    // printGraph();
    return 0;
}