#include <bits/stdc++.h>
using namespace std;

#define INF 99
#define V 4

void floydWarshall(int g[][V])
{
    for(int k =  0; k < V; k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j = 0; j<V;j++)
            {
                if((g[i][j]> g[i][k]+g[k][j]) and  (g[i][k]!=INF) and  (g[k][j]!=INF)){
                    g[i][j] = g[i][k]+g[k][j];
                }

            }
        }
    }

    for(int i=0;i<V;i++)
    {
        for(int j =0;j<V;j++)
        {
            if(g[i][j]==INF)cout<<"INF ";
            else cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    //int n;cin>>n;
    int g[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j = 0;j<V;j++)cin>>g[i][j];
    }
    floydWarshall(g);
    return 0;
}