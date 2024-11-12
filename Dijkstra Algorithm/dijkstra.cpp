#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
typedef pair<int,int>pii;
const int N =105;
vector<vector<int>>g[N];
vector<int>dis(N,inf);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;cin>>n>>m;
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    int src;cin>>src;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dis[src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto &neighbor:g[u])
        {
            int v = neighbor[0];
            int weight = neighbor[1];
            if(dis[u]+weight<dis[v])
            {
                dis[v] = dis[u]+weight;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" "; 
    }
    return 0;
}