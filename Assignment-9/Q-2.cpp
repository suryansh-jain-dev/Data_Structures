#include <iostream>
using namespace std;

int g[20][20],vis[20],n;

void dfs(int v){
    cout<<v<<" ";
    vis[v]=1;
    for(int i=0;i<n;i++)
        if(g[v][i]==1 && vis[i]==0) dfs(i);
}

int main(){
    int e,u,v,start;
    cin>>n>>e;
    for(int i=0;i<e;i++){ cin>>u>>v; g[u][v]=g[v][u]=1; }
    cin>>start;
    dfs(start);
}