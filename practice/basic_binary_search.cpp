#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int nums[] = {
        2,
        3,
        5,
        7,
    },
        target = 7;
    int l = 0, r = 3;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
        {
            cout << "found" << endl;
            return 0;
        }
        else if (nums[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << "Not found";
    return 0;
}