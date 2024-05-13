#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int knapsack(int n, vector<int> &wt, vector<int>&val, int W)
{
    vector<vector<int>> dp (n+1, vector<int> (W+1,0));
    for (int i=1; i<=n; i++)
    {
        for (int w =1; w<=W; w++)
        {
            if (wt[i-1] > w)
            {
                dp[i][w] = dp[i-1][w];
            }
            else
            {
                dp[i][w] = max (val[i-1] + dp [i-1][w - wt[i-1]], dp[i-1][w] );
            }
        }
    }
    return dp[n][W];

}
int main ()
{
    int n; cin>>n;
    int W; cin>>W;
    vector<int>wt;
    vector<int>val;
    for (int i=0; i<n; i++)
    {
        int w,v;
        cin>>w>>v;
        wt.push_back(w);
        val.push_back(v);
    }
    cout<<knapsack(n,wt,val,W);
   
}