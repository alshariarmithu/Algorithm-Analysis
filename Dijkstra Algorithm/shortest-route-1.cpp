#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define lb "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define LB cout << lb
typedef pair<int,int> pii;
const int inf = INT_MAX;
#define all(v) v.begin(), v.end()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<pii>adj[100005];
bool vis[100005];
int dis[100005];


int main()
{    
    fastIO;
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    for(int i=2;i<=n;i++)dis[i]=inf;
    dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:adj[u]){
            if(dis[u]+w<dis[v]){
                dis[v] = w+dis[u];
                q.push({dis[v],v});
            }
        }
    }
    for(int i =1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    LB;
    return 0;
}