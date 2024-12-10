#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define lb "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define LB cout << lb
typedef pair<int,int>pii;
#define all(v) v.begin(), v.end()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<pii>g[100005];
int dis[100005];

int main()
{    
    fastIO;
    ll t, cs = 1;
    cin >> t;
    while (t--)
    {
        map<string,int>mp;
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            string x;cin>>x;
            int p;cin>>p;
            mp[x] = i;
            for(int i=1;i<=p;i++)
            {
                int v,w;cin>>v>>w;
                g[i].push_back(make_pair(v,w));
            }

        }
        int r;cin>>r;
        for(int i=0;i<r;i++)
        {
            string a,b;cin>>a>>b;
            int u = mp[a];
            int v = mp[b];

            for(int j=0;j<=n;j++)
            {
                dis[j] = 1e9;
            }
            dis[u]= 0;
            priority_queue<pii,vector<pii>,greater<pii>>q;
            q.push({dis[u],u});
            while(!q.empty()){
                int u = q.top().second;
                q.pop();
                for(auto [v,w]:g[u]){
                    if(dis[u]+w<dis[v]){
                        dis[v] = dis[u]+w;
                        q.push({dis[v],v});
                    }
                }
            }
            cout<<dis[v]<<lb;
        }
        for(int i=0;i<=n;i++){
            g[i].clear();
        }
        mp.clear();
    }
    return 0;
}