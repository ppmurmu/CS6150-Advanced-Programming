#include <iostream>
using namespace std;

int wt[] = {10, 20, 30};
int val[] = {60, 100, 120};

int m = 50;
int n = 3;
int dp[3][51];
int main()
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (wt[i] == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i] <= j)
            {
                dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[2][50];
    return 0;
}