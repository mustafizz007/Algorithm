#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
const int mx = 1e4+123;
vector <int> adj[mx];
int lev[mx];

void bfs(int s)
{

    memset (lev , -1, sizeof(lev));
    lev[s] = 0;

    queue<int> q;

    q.push(s);
    

    while (!q.empty())
    {
        /* code */
        int u = q.front();
        q.pop();

        for (auto i : adj[u])
        {
            if (lev[i] == -1)
            {
                lev[i] = lev[u] + 1;
                q.push(i);
            }
        }
    }
    
}
void solve ()
{
    for (int i =0; i< mx; i++) adj[i].clear();

   int n , m; cin >> n >> m;

   for (int i =0; i<m; i++)
   {
    
    int u, v; cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);


   }

   bfs(1);

   cout << lev[n] <<endl;


}

int main ()
{
    opt();
    int t; cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}