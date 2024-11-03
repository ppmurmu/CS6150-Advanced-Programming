#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 4;
    vector<vector<int>> jobs = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};

    // each job takes 1 unit time
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] > b[1]; });

    vector<int> slot(5, -1);
    int sum = 0;
    for (auto it : jobs)
    {
        if (slot[it[0]] == -1)
        {
            slot[it[0]] = 1;
            sum += it[1];
        }
    }

    cout << sum << endl;

    return 0;
}