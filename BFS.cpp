#include<bits/stdc++.h>
using namespace std;
void BFS(vector <vector<int> > &graph, int start, vector<bool> &visited)
{
    queue <int> q;
    visited [start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";

        for (int i =0; i< graph[u].size(); i++)
        {
            int v = graph [u][i];

            if (visited[v] == false)
            {
                q.push(v);
                visited [v] = true;
            }
        }
        q.pop();
    }

}
int main()
{
    int v, e;
    cin>>v>>e;

    vector<vector<int>> graph(v+1);

    for (int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=v; i++)
    {
        cout<<"vertex : "<<i<<"-> ";

        for (int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<bool>visited(v+1, false);
    BFS (graph, 1, visited);

}
