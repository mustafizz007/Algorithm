#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int lcs(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1 , 0));
    
    for(int i=1; i<=n; i++) 
    {
        for (int j=1; j<=m; j++)
        {
            if (x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] =max (dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}
string lcsString(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1 , 0));
    
    for(int i=1; i<=n; i++) 
    {
        for (int j=1; j<=m; j++)
        {
            if (x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] =max (dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int i = n;
    int j = m;
    string lcs = "";
    while (i> 0 && j> 0)
    {
        if (x[i-1] == y[j-1])
        {
            lcs = x[i-1] + lcs;
        }
        else if (dp[i-1][j] >  dp[i][j-1])
        {
            i--;
        }
        else j--;
    }
    return lcs;
}
int main ()
{
    string x,y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    cout<<lcs(x,y,n,m)<<endl;
    cout<<lcsString(x,y,n,m);
}