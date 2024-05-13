#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int color [100];
int n,e;
#define WHITE 1
#define GRAY 2
#define BLACK 3
print_dfs(int x)
{
    cout<<x<<" ";
}
void dfs_visit(int x)
{
    color[x] = GRAY;

    for (int i=0; i<n; i++)
    {
        if (a[x][i] == 1)
        {
            if (color[i] == WHITE)
            {
                print_dfs(i);
                dfs_visit(i);
            }
        }
    }
    color [x] = BLACK;
}
void dfs()
{
    for (int i=0; i<n; i++)
    {
        color[i] = WHITE;
    }
    for (int i=0; i<n; i++)
    {
        if (color [i] == WHITE)
        {
            print_dfs(i);
            dfs_visit(i);
        }
    }
}

int main()
{

    freopen("input file.txt", "r", stdin);
    //int n,e;
    cin>>n>>e;

    int u, v;

    for (int i=0; i<e; i++)
    {
        cin>>u>>v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    //showing connection with one node and another
    for (int i=0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {

            cout<<a[i][j]<<"\t";

        }
        cout<<endl;
    }
    //showing neighbour of a node
    for (int i=0; i<n; i++)
    {
        cout<<i<<"->";
        for (int j =0; j<e; j++)
        {

            if (a[i][j] == 1)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    dfs();
}
