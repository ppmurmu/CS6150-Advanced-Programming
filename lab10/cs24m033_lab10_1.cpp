#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char city[1001][1001];

//to store all possible directions from current location
int dir[8][2]={{-1,-1},{-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

//check vlaid move
bool checkValidMove(int i, int j, int n, int m)
{
    if(i<0 || i>=n || j<0 || j>=m || city[i][j]=='V')
    {
        return false;
    }
    if(city[i][j]=='#')
    {
        return false;
    }
    return true;
}


void bfs(int oi, int oj, int n , int m)
{
    queue<vector<int>> q; //store index i, j and distance
    q.push({oi, oj, 0});
    city[oi][oj]='V';
    int c=0; //store steps
    int res_i, res_j;
    while(!q.empty())
    {
        vector<int> curr= q.front();
        q.pop();
        if(city[curr[0]][curr[1]] == 'H')
        {
            //cout<< "steps " << curr[0] << " "<< curr[1] << " " << curr[2]<< endl;
            res_i=curr[0];
            res_j=curr[1];
            c=curr[2];
            break;
        }
        for(int i=0; i< 8; i++)
        {
            if(checkValidMove(curr[0]+dir[i][0], curr[1]+dir[i][1], n , m))
            {

                q.push({curr[0]+dir[i][0], curr[1]+dir[i][1], curr[2]+1});
                if( city[curr[0]+dir[i][0]][curr[1]+dir[i][1]]=='.')
                city[curr[0]+dir[i][0]][curr[1]+dir[i][1]]='V'; //visited
            }
        }
    }
    if(c==0)
        cout <<-1 ;
    else
    {
    cout << c*5 << endl;
    cout << "(" << res_i << "," << res_j << ")" ;
    }
    
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n;
    cin >> m;
    int oi=-1, oj=-1; //store origin value
    for(int i=0; i<n;i++)
    {
        for(int j=0 ; j< m ;j++)
        {
            
            cin>>city[i][j];
            if(city[i][j]=='X')
            {
                oi=i;
                oj=j;
            }
        }    
    }
    bfs(oi ,oj,n , m);
    
    
    return 0;
}
