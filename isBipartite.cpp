//bipartite
#include<iostream>
using namespace std;
#include<cstdlib>
#include<queue>
struct node {
int data;
struct node *next;
};
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
int visited[n]={0};
int source=1;
queue<int> q;
q.push(source);
visited[source-1]=1;int color[n]={-1};color[source-1]=1;bool bi=1;
while(q.empty()==0)
{

    node *temp=adj[q.front()-1];
    while(temp!=NULL)
    {
       if(visited[temp->data-1]==0)
       {
           q.push(temp->data);
           visited[temp->data-1]=1;color[temp->data-1]=(color[q.front()-1]==0)?1:0;
       }
       else{
        if(color[q.front()-1]==color[temp->data-1])
        {
            bi=0;
            break;
        }
       }
       temp=temp->next;
    }
    if(bi==0)break;
    q.pop();
}
if(bi==0)cout<<"not a bipartite"<<endl;
else
    cout<<"bipartite"<<endl;
}
