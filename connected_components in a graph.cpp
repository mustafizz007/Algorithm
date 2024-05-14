#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)

const int mx = 1e5+123;
vector <int> adj[mx];
int vis[mx];

void dfs (int x){

    vis[x] = 1;
    for (auto i : adj[x])
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(i);

        }
    }
}

void solve ()
{
   int n, e; cin >> n >> e;

   for (int i =0; i < e; i++)
   {

    int u, v; cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

   }

int cnt =0;

   for (int i =1; i<=n; i++)
   {
    if (vis[i] == 1) continue;
    else {
        dfs(i);
        cnt++;
    }
   }
   cout << cnt << endl; 


}

int main ()
{
    opt();

        solve();
    
}