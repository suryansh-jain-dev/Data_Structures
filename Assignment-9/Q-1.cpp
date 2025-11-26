#include <iostream>
using namespace std;

int main(){
    int n,e,u,v,start;
    cin>>n>>e;
    int g[20][20]={0};
    for(int i=0;i<e;i++){ cin>>u>>v; g[u][v]=g[v][u]=1; }

    cin>>start;
    int vis[20]={0};
    int q[50],front=0,rear=0;

    q[rear++] = start;
    vis[start]=1;

    while(front < rear){
        int x = q[front++];
        cout<<x<<" ";

        for(int i=0; i<n; i++){
            if(g[x][i]==1 && vis[i]==0){
                vis[i]=1;
                q[rear++] = i;
            }
        }
    }
}