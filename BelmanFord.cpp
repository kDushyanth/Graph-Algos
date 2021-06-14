#include<iostream>
using namespace std;
typedef struct node{
int v1,v2,w;
}node;
int main()
{
    int n,e;
    cin>>n>>e;
    node adj[e];
    for(int i=0;i<e;i++)
    {
        int a,c,b;cin>>a>>b>>c;
        adj[i].v1=a;
        adj[i].v2=b;
        adj[i].w=c;
    }
    int n1=n-1;
    int du[n];
    int p[n];
    for(int i=0;i<n;i++)
    {
        du[i]=10000;
        p[i]=-1;
    }
    du[0]=0;
    //for(int i=0;i<n;i++)cout<<du[i]<<endl
    while(n1--)
    {
        for(int i=0;i<e;i++)
        {
            if(du[adj[i].v1-1]+adj[i].w < du[adj[i].v2-1])
            {
                du[adj[i].v2-1]=du[adj[i].v1-1]+adj[i].w;p[adj[i].v2-1]=adj[i].v1;
            }
        }

    }
    int b=0;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<du[i]<<endl;
    }
  for(int i=0;i<e;i++)
{
    if(du[adj[i].v1-1]+adj[i].w < du[adj[i].v2-1])
    {
        b=1;
        break;
    }
}
if(b==0)cout<<"has cycle"<<endl;
if(b==1)cout<<"doesn't have a cycle"<<endl;
}
