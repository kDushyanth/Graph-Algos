//question - 1
#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
typedef struct node{
int data;
struct node *next;
}node;
void gprint(node *adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        node *temp=adj[i];
        cout<<i+1<<"->";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    node *adj[n]={NULL};
    int e,a,b;cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        node *nn1=(node*)malloc(sizeof(node));
        nn1->data=b;
        nn1->next=NULL;
        node *nn2=(node*)malloc(sizeof(node));
        nn2->data=a;
        nn2->next=NULL;
        if(adj[a-1]==NULL)
        {
            adj[a-1]=nn1;
        }
        else
        {
            node *temp=adj[a-1];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn1;
        }
        if(adj[b-1]==NULL)
        {
            adj[b-1]=nn2;
        }
        else
        {
            node *temp=adj[b-1];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn2;
        }
    }
    gprint(adj,n);
cout<<"-------------------"<<endl;
int source;
cout<<"enter source"<<endl;
cin>>source;
queue<int> q;int visited[n]={0};
q.push(source);
visited[source-1]=1;
while(q.empty()==0)
{
    node *temp=adj[q.front()-1];
    while(temp!=NULL)
    {
        if(visited[temp->data-1]==0)
        {
            q.push(temp->data);
            visited[temp->data-1]=1;
        }
        temp=temp->next;
    }
    cout<<q.front()<<" ";
    q.pop();
}
}
