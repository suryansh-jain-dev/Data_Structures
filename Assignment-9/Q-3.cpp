#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{ int u,v,w; };
Edge a[50];
int parent[20];

int find(int x){ if(parent[x]==x) return x; return parent[x]=find(parent[x]); }

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a,a+e,[](Edge x,Edge y){ return x.w<y.w; });
    for(int i=0;i<n;i++) parent[i]=i;
    int cost=0,c=0;
    for(int i=0;i<e;i++){
        int x=find(a[i].u), y=find(a[i].v);
        if(x!=y){
            cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
            cost+=a[i].w;
            parent[y]=x;
            c++; if(c==n-1) break;
        }
    }
    cout<<"Cost "<<cost;
}