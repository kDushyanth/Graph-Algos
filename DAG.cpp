#include<iostream>
#include<cstdlib>
using namespace std;
#include<stack>
typedef struct node{
int data;
int w;
struct node *next;
}node;
int tim=0;
stack <int> s;
void print(node *adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"->";
        node *temp=adj[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<"--"<<temp->w<<" ";
            temp=temp->next;
        }cout<<endl;
    }
}
void dfs(node *adj[],int n,int source,int d[],int r[],int v[],int p[])
{
    tim++;
    d[source-1]=tim;
    v[source-1]=1;
    node *temp=adj[source-1];
    while(temp!=NULL)
    {
        if(v[temp->data-1]==0)
        {
            p[temp->data-1]=source;
            dfs(adj,n,temp->data,d,r,v,p);
        }
        temp=temp->next;
    }
    tim++;s.push(source);
    r[source-1]=tim;
}
int main()
{
    int n,e;
    cin>>n>>e;
    node *adj[n]={NULL};
    for(int i=0;i<e;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        node *nn=(node *)malloc(sizeof(node));
        nn->data=b;
        nn->w=c;
        nn->next=NULL;
        node *temp=adj[a-1];
        if(temp==NULL)adj[a-1]=nn;
        else{
            while(temp->next!=NULL)temp=temp->next;
            temp->next=nn;
        }
    }
//print(adj,n);cout<<endl;
int sou;cout<<"enter source"<<endl;
cin>>sou;int v[n]={0},p[n]={-1},r[n],d[n];
dfs(adj,n,sou,d,r,v,p);
int du[n];
for(int i=0;i<n;i++)
    du[i]=INT_MAX;
du[sou-1]=0;
while(s.empty()==0)
{
    node *temp=adj[s.top()-1];
    while(temp!=NULL)
    {
        if(du[s.top()-1]+temp->w < du[temp->data-1])
            du[temp->data-1]=temp->w+du[s.top()-1];
        temp=temp->next;
    }
    s.pop();
}
for(int i=0;i<n;i++)cout<<du[i]<<endl;
}
