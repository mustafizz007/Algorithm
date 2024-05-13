#include<bits/stdc++.h>
using namespace std;
#define v 4
int mincost(int cost[], bool mstset[])
{
    int min = INT_MAX;
    int min_index;
    for (int i=0; i<v; i++)
    {
        if (mstset[i] == false && cost [i] < min)
        {
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}
void printmst(int parent[], int graph[v][v])
{
    cout<<"edge \t cost"<<endl;
    for (int i=1; i<v; i++)
    {
        cout<<parent[i]<<" "<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}
void primsMST(int graph[v][v])
{
    int parent [v], cost[v];
    bool mstset[v];
    for (int i=0; i<v; i++)
    {
        cost[i] = INT_MAX;
        mstset[i] = false;
    }
    cost[0] = 0;
    parent [0] = -1;
    for (int i=0; i<v-1; i++)
    {
        int u = mincost(cost, mstset);
        mstset[u] = true;
        for (int j= 0; j<v; j++)
        {
            if (graph[u][v] && mstset[j] == false && graph[u][j] < cost[j])
            {
                parent [j] = u;
                cost[j] = graph[u][j];
            }
        }
    }
    printmst(parent, graph);
}
int main()
{
    int graph[v][v] = {{0,1,0,4}, {1,0,1,3}, {0,1,0,1}, {4,3,1,0}};
    primsMST(graph);
}
