#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int source,destination,weight;
};

void bellmanFord(int n , int m ,vector<Edge>&g, int src){
    vector<int>dis(n,INT_MAX);
    dis[src] = 0;

    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 0; j<m; j++)
        {
            int u = g[j].source;
            int v = g[j].destination;
            int w = g[j].weight;

            if(dis[u]!= INT_MAX and dis[v]> w + dis[u]){
                dis[v] = dis[u]+w;
            }
        }
    }
    for(int j = 0;j< m; j++)
    {
        int u = g[j].source;
        int v = g[j].destination;
        int w = g[j].weight;
        if(dis[u]!=INT_MAX and dis[v]>w+dis[u])
        {
            cout<<"Negative Weight Cycle\n";
            return;
        }
    }
    for(int i = 0; i < n ; i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }
}

int main()
{
    
    return 0;
}
