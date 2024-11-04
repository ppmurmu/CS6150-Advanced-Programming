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
    int total_choco=0;

    for(int i=0; i<n;i++)
    {
        cin >> B[i];
        total_choco+=B[i];
    }
    //check if total num of chocolates is odd or even.
    //if odd then obviously we cant split equally
    if(total_choco%2!=0)
    {
        cout<<"no";
        return 0;
    }

    int curr_sum=0; //to store the current sum of chocolates
    
    //vector<int> first; //to store the chocolates in first half  

    int s=0;
    for(int  i=0; i<n; i++)
    {
        curr_sum+=B[i];
        //first.push_back(B[i]);

        if(total_choco/2==curr_sum)
        {
            //we have split equally
            s=i;
            break;
        }

        if(curr_sum > total_choco)
        {
            //we couldn't find an s for which we could split B in two halves
            cout<<"no";
            return 0;
        }
    }

    if(total_choco/2==curr_sum)
    {
        cout << "yes" << endl;
        for(int i=0; i< n; i++)
        {
            cout<< B[i] << " ";
            if(i==s)
            {
                cout << endl;
            }
        }
    }
    else{
        cout<<"no";
    }
    return 0;
}