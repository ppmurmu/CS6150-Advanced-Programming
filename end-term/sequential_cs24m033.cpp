//link/ether 30:13:8b:69:ef:0f brd ff:ff:ff:ff:ff:ff

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> backtrack(int curr, int target_sum, int B[], int n, vector<int> &res)
{
    if(target_sum==0)
    {
        return res;
    }
    if(curr >= n)
    {
        return {};
    }
    if(B[curr] > target_sum)
    {
        return {};
    }
    for(int i=0; i< n; i++)
    {
        if(target_sum - B[i] == 0)
        {
            res.push_back(B[i]);
            return res;
        }

        backtrack(i, target_sum- B[i], B, n , res);
        
        //remove the last element if it fails
        res.pop_back();

    }
    return {};
    
}



int main()
{
    int n;
    cin >> n;

    //decide yes or no in O(1)
    int total_choco= (n*(n+1))/2;
    if(total_choco%2==0)
    {
        cout<< "yes" << endl;
    }
    else{
        cout << "no" << endl;
        return 0;
    }


    int B[n];
    for(int i=0; i<n;i++)
    {
        B[i]=i+1;;
    }
    //to store the target sum which is half of the total chocolates
    int target_sum=total_choco/2;

    //to store the result
    vector<int> res;


    vector<int> t =backtrack(0, target_sum, B, n , res);

    for(int i=0; i< t.size(); i++)
    {
        cout << B[i] <<" ";

    }

    return 0;
}