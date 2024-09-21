#include <iostream>
using namespace std;

int arr[] = {2, 5, 7, 81, 1};
void swap(int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
void bubbleSort()
{
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(j, j + 1);
            }
        }
    }
}
void print()
{
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    bubbleSort();
    print();

    return 0;
}