#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet (int V)
    {
        parent.resize(V+1);
        size.resize(V+1);
        for(int i=0;i<=V;i++)
        {
            parent[i]=i;
            size[i]= 1;
        }
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionSet(int i, int j)
    {
        int xRoot = find(i);
        int yRoot = find(j);
        if (xRoot != yRoot)
        {
            if (size[xRoot] < size[yRoot])
            {
                parent[yRoot] = xRoot;
                size[xRoot]+=size[yRoot];
            }
            else if (size[xRoot] > size[yRoot])
            {
                parent[xRoot] = yRoot;
                size[yRoot]+=size[xRoot];
            }
            else
            {
                parent[yRoot] = xRoot;
                size[xRoot]++;
            }
        }
    }
};
int MST(vector<vector<int>> adj[], int V)
{
    int node = 0;
    vector<pair<int, pair<int, int>>> g;
    DisjointSet Parent(V);
    for (int i = 0; i < V; i++)
    {
        for (auto elem : adj[i])
        {
            int v = elem[0];
            int w = elem[1];
            g.push_back({w, {i, v}});
        }
    }
    sort(g.begin(), g.end());
    int sum = 0;
    for (auto e : g)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (Parent.find(u) != Parent.find(v) and node <= V - 1)
        {
            sum += w;
            node++;
        }
    }
    return sum;
}
int main()
{
    // cout<<66<<endl;
    return 0;
}