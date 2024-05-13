#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int minCoins(vector<int>&coins, int V, int m)
{
    int table[V+1];
    int coinsUsed[V+1];
    table[0] = 0;
    coinsUsed[0] = -1;
    for (int i=1; i<=V; i++)
    {
        table[i] = INT_MAX; 
        coinsUsed[i] = -1;
    }
    for (int i=1; i<=V; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if (coins[j] <= i)
            {
                int res = table[i - coins[j]];
                if (res != INT_MAX && res +1 < table[i])
                {
                    table[i] = res +1;
                    coinsUsed[i] = j;
                }
            }
        }

    }
    if (table[V] == INT_MAX) 
    {
        cout<<"not possible"<<endl;
        return -1;
    } 
    cout<<"min no. of coins"<<table[V]<<endl;
    cout<<"coins are ";
    int value = V;
    while (value >0)
    {
        int coinIndex = coinsUsed[value];
        cout<<coins[coinIndex]<<" ";
        value = value - coins[coinIndex];
    }
    cout<<endl;
}
int main ()
{
   int v; cin>>v;
   int m; cin>>m;
   vector<int> coins(m);
   for (int i=0; i<m; i++) cin>>coins[i];
   minCoins(coins,v,m);
}