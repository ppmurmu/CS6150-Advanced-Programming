#include <iostream>
using namespace std;

int partition(int ar[], int low, int high)
{
    int pivot = ar[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ar[j] < pivot)
        {
            // swap
            i++;
            int t = ar[i];
            ar[i] = ar[j];
            ar[j] = t;
        }
    }
    int t = ar[i + 1];
    ar[i + 1] = ar[high];
    ar[high] = t;

    return i + 1;
}
void quickSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(ar, low, high);
        quickSort(ar, low, pi - 1);
        quickSort(ar, pi + 1, high);
    }
}

int main()
{
    int ar[] = {4, 1, 8, 3, 9, 5, 2};
    quickSort(ar, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << ar[i] << " ";
    }
}
