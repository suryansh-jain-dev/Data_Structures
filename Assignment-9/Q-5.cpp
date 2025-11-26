#include <iostream>
using namespace std;

int main(){
    int n,src;
    cin>>n;
    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>g[i][j];

    cin>>src;
    int dist[20],vis[20]={0};
    for(int i=0;i<n;i++) dist[i]=999;
    dist[src]=0;

    for(int c=0;c<n-1;c++){
        int u=-1,min=999;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<min){ min=dist[i]; u=i; }
        vis[u]=1;

        for(int v=0;v<n;v++)
            if(g[u][v]!=0 && dist[u]+g[u][v]<dist[v])
                dist[v]=dist[u]+g[u][v];
    }

    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}