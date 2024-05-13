#include<bits/stdc++.h>
using namespace std;

int minCoinsUtil(int coins[], int m, int v, vector<int>&dp)
{
    if (v==0) return 0;
    if (dp[v] != -1) return dp[v];
    int ans = INT_MAX;

    for (int i=0; i<m; i++)
    {
        if (coins[i] <= v)
        {
            int  a = minCoinsUtil(coins, m, v - coins [i], dp);
            if (a != INT_MAX && a+1 < ans) ans = a+1;
        }
    }
            dp [v] = ans;
            return dp[v];
}
int main()
{
    int v;
    cin>>v;
    vector<int>dp(v+1,-1);
    int m;
    cin>>m;
    int coin[m];
    for(int i=0;i<m;i++)cin>>coin[i];
    cout<<minCoinsUtil(coin, m, v, dp);
}
