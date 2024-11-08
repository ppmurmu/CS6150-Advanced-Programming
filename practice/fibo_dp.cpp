#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    vector<int> dp(10 + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}