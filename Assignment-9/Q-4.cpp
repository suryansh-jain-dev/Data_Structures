#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>g[i][j];

    int vis[20]={0};
    vis[0]=1;
    int edges=0,cost=0;

    while(edges<n-1){
        int min=999,x=0,y=0;
        for(int i=0;i<n;i++)
            if(vis[i])
                for(int j=0;j<n;j++)
                    if(!vis[j] && g[i][j]!=0 && g[i][j]<min){
                        min=g[i][j]; x=i; y=j;
                    }

        cout<<x<<" "<<y<<" "<<min<<endl;
        vis[y]=1;
        cost+=min;
        edges++;
    }
    cout<<"Cost "<<cost;
}