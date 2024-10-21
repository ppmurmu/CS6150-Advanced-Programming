#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long b[1000001];

bool validity(long long k, long long n, long long m)
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        // return true if sum is already greater than m
        if (sum >= m)
        {
            return true;
        }
        if (b[i] < k)
        {
            sum += b[i];
        }
        else
        {
            sum += k;
        }
    }
    return (sum >= m);
}

long long findNextValidData(long long n, long long val)
{
    long long mini = LLONG_MAX;
    for (long long i = 0; i < n; i++)
    {
        if (b[i] >= val)
        {
            mini = min(mini, b[i]);
        }
    }
    return mini;
}

void crunchBS(long long m, long long n)
{
    long long maxi = LLONG_MIN;
    long long mini = LLONG_MAX;
    for (long long i = 0; i < n; i++)
    {
        maxi = max(maxi, b[i]);
        mini = min(mini, b[i]);
    }

    long long l = mini, r = maxi;
    long long res = maxi;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (validity(mid, n, m))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    res = findNextValidData(n, res);
    cout << res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    long long m;
    cin >> n;
    cin >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // crunch data using binary search
    crunchBS(m, n);
    return 0;
}
