//link/ether 30:13:8b:69:ef:0f brd ff:ff:ff:ff:ff:ff

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int B[n];
    int t=0; //to store total number of chocolate
    for(int i=0; i<n;i++)
    {
        cin >> B[i];
        t+=B[i];
    }

    //we cant split odd num of chocloaate
    if(t%2!=0)
    {
        cout<< "no" << endl;
        return 0;
    }
    int target_sum=t/2; //if we can reach the half number of chocolate then we have achieved our split

    //dp to calculate the sum
    vector<vector<int>> dp(n, vector<int>((target_sum+1), 0));

    
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<target_sum+1; j++)
        {
            //base case
            if(dp[i][j]==0 || dp[i][j] > j)
            {
                dp[i][j]=0;
            }
            if(i>0 && j>0)
            {
                dp[i][j] = dp[i-1][j-1];

            }
            
        }
    }
   
    return 0;
}