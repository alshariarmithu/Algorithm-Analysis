#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define lb "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define LB cout << lb
#define all(v) v.begin(), v.end()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()
{    
    fastIO;
    ll t, cs = 1;
    int n,m;cin>>n>>m;
    vector<vector<int>>g;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g.push_back({u,v,w});
    }
    vector<int>dis(n+2,1e9);
    int src = 1;
    dis[src] = 0;
    for(int i=1;i<=n;i++)
    {
        for(auto e:g){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dis[u]+w<dis[v] && dis[u]!=1e9){
                dis[v] = dis[u]+w;

                if(i==n){
                    cout<<-1<<lb;
                    return 0;
                }
            }
        }
    }
    cout<<dis[n]<<endl;
    return 0;
}