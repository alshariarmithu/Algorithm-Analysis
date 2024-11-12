#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<vector<int>>g[N];
vector<int>dis(N,1e7);

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
    set<pair<int,int>>st;
    dis[src] = 0;
    st.insert({0,src});
    while(!st.empty())
    {
        auto it = *(st.begin());
        int u = it.second;
        //int weight = it.first;
        st.erase(it);

        for(auto it:g[u])
        {
            int v = it[0];
            int weight = it[1];
            if(dis[u]+weight < dis[v])
            {
                dis[v] =dis[u]+weight;
                st.insert({dis[v],v});
            }
        }
    }
    return 0;
}