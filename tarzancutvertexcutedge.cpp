#include<iostream>
#include<cstdlib>
using namespace std;
#include<stack>
typedef struct node{
int data;
struct node *next;
}node;
int tim=0;int coun=0;
void dfs(node *adj[],int n,int sou/*source*/,int p[],int d[],int v[],int f[])
{
    tim++;
    d[sou-1]=tim;
    f[sou-1]=tim;
    v[sou-1]=1;
    node *temp=adj[sou-1];
    temp=adj[sou-1];
    while(temp!=NULL)
    {   
        if(v[temp->data-1]==1 && /*p[temp->data-1]!=sou &&*/ p[sou-1]!=temp->data && d[temp->data-1]<d[sou-1])
        {//visited node
            f[sou-1]=min(f[sou-1],d[temp->data-1]);
        }
        if(v[temp->data-1]==0)
        {//unvisited node
            p[temp->data-1]=sou;
            if(sou==1)coun++;
            dfs(adj,n,temp->data,p,d,v,f);
            f[sou-1]=min(f[sou-1],f[temp->data-1]);
            if(d[sou-1] <= f[temp->data-1] && sou!=1)cout<<sou<<"-cut vertex"<<endl;
            if(d[sou-1] <  f[temp->data-1] )cout<<sou<< " "<<temp->data<<"-cut edge"<<endl;
        }
        temp=temp->next;
    }
}
int main()
{
    int n,e;cin>>n>>e;
    node *adj[n]={NULL};
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        node *nn=(node *)malloc(sizeof(node));
        nn->next=NULL;
        nn->data=b;
        node *temp=adj[a-1];
        if(temp==NULL)adj[a-1]=nn;
        else{
            while(temp->next!=NULL)temp=temp->next;
            temp->next=nn;
        }
    }
    int
    p[n],d[n],v[n],f[n],visited[n];
    for(int i=0;i<n;i++)
    {
        p[i]=-1;//parent
        d[i]=-1;//disc time
        v[i]=0;//visit
        f[i]=-1;//finish time
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)dfs(adj,n,i+1,p,d,v,f);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<f[i]<<endl;
    }
    if(coun>1)cout<<"-1 cut vertex"<<endl;
}
