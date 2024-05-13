#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int maxWays(vector<int> &coins, int n,int m)
{
    vector<vector<int>> dp (n+1 , vector<int> (m+1, 0));
    dp[0][0] = 1;
    for (int i =1; i<=n; i++)
    {
        for(int j =0; j<=m; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j - coins[i-1] >=0)
            {
                dp[i][j] += dp[i][j-coins[i-1]]; 
            }
        }
    }
    return dp[n][m];
}
int main ()
{
    
    int n; cin>>n;
    int m; cin>>m;
    vector<int> coins(n);
    for (int i=0; i<n; i++)
    {
        cin>>coins[i];
    }
    cout<<maxWays(coins, n,m)<<endl;
}