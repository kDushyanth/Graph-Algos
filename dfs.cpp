#include<iostream>
using namespace std;
#include<cstdlib>
#include<queue>
struct node {
int data;
struct node *next;
};
int time=0;
void dfs(node *adj[],int n,int source,int parent[],int visited[],int disc[],int finish[])
{
 visited[source-1]=1;
 cout<<" "<<source<<" ";
 node *temp=adj[source-1];
 time++;
 disc[source-1]=time;
 while(temp!=NULL)
 {
     if(visited[temp->data-1]==0)
     {
         parent[temp->data-1]=source;
         dfs(adj,n,temp->data,parent,visited,disc,finish);
     }
     temp=temp->next;
 }
 time++;
 finish[source-1]=time;
}
print(node *adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        node *temp=adj[i];
        cout<<i+1<<" ";
        while(temp!=NULL)
        {
            cout<<" ->"<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;int a,b;
    node *adj[n];
    for(int i=0;i<n;i++)
      adj[i]=NULL;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        node *nn1=(node *)malloc(sizeof(node));
        nn1->next=NULL;nn1->data=b;
        node *nn2=(node *)malloc(sizeof(node));
        nn2->next=NULL;nn2->data=a;
        if(adj[a-1]==NULL)adj[a-1]=nn1;
        else{
            node *temp=adj[a-1];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=nn1;
        }
         if(adj[b-1]==NULL)adj[b-1]=nn2;
        else{
            node *temp=adj[b-1];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=nn2;
        }
    }
    print(adj,n);
int parent[n]={-1};
int visited[n]={0};int disc[n],finish[n];
int source;
//dfs(adj,n,source,parent,visited,disc,finish);
cout<<endl;
for(int i=0;i<n;i++)
{
    if(visited[i]==false)
        dfs(adj,n,i+1,parent,visited,disc,finish);
    cout<<endl;
}
for(int i=0;i<n;i++)
{
   cout<<disc[i]<<" "<<finish[i]<<endl;
}
}

