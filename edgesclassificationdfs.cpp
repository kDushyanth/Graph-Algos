#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node {
int data;
struct node *next;
}node;
int tim=0;
void pcycle(int parent[],int source,int temp)
{
    if(source==temp)cout<<temp<<" ";
    else{
         pcycle(parent,parent[source-1],temp);
         cout<<source<<" ";
    }
}
void dfs(node *adj[],int n,int source,int visited[],int parent[],int d[],int f[])
{
    visited[source-1]=1;
    tim++;
    d[source-1]=tim;

    node *temp=adj[source-1];
    while(temp!=NULL)
    {
        if(visited[temp->data-1]==0)
        {
            parent[temp->data-1]=source;
            dfs(adj,n,temp->data,visited,parent,d,f);
        }
    else{
        if(visited[temp->data-1]==1 && parent[temp->data-1]!=source && f[temp->data-1]==-1)
        {
            pcycle(parent,source,temp->data);
            cout<<endl;
        }}
        temp=temp->next;
    }
    tim++;
    f[source-1]=tim;
}
int main()
{
    int n,e;
    cin>>n>>e;
    node *adj[n]={NULL};
    for(int i=0;i<e;i++)
    {
      int a,b;
      cin>>a>>b;
        node *nn=(node *)malloc(sizeof(node));
        nn->data=b;
        nn->next=NULL;
        node *temp=adj[a-1];
        if(adj[a-1]==NULL)
            adj[a-1]=nn;
        else
        {
            while(temp->next!=NULL)temp=temp->next;
            temp->next=nn;
        }
    }
    int visited[n]={0},parent[n]={-1};
int d[n]={-1},f[n]={-1};
for(int i=0;i<n;i++)
{
    d[i]=-1;
    f[i]=-1;
    parent[i]=-1;
    visited[i]=0;
}
for(int i=0;i<n;i++)
{
    if(visited[i]==0)
    dfs(adj,n,i+1,visited,parent,d,f);
}
cout<<endl<<"-------------------------"<<endl;
/*
for(int i=0;i<n;i++)
{
    node *temp=adj[i];
    while(temp!=NULL)
    {
        if(d[i]<d[temp->data-1] && f[temp->data-1]<f[i] && parent[temp->data-1]==i+1)
            cout<<i+1<<" "<<temp->data<<"-tree edge"<<endl;
        if(d[i]<d[temp->data-1] && f[temp->data-1]<f[i] && parent[temp->data-1]!=i+1)
            cout<<i+1<<" "<<temp->data<<"-forward edge"<<endl;
        if(d[i]>d[temp->data-1] && f[temp->data-1]>f[i]&& parent[temp->data-1]!=i+1)
            cout<<i+1<<" "<<temp->data<<"-back edge"<<endl;
        if(f[temp->data-1]<d[i] && parent[temp->data-1]!=i+1)
            cout<<i+1<<" "<<temp->data<<"-cross edge"<<endl;
        temp=temp->next;
    }
}
*/

}
