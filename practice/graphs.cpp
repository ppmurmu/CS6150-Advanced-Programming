#include <iostream>
using namespace std;

class Graph
{
public:
    int *ar;
    int **matrix;
    Graph(int size)
    {
        ar = new int[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g = Graph(5);
    for (int i = 0; i < 5; i++)
    {
        g.matrix[i][i] = 1;
    }
    g.display();
    return 0;
}