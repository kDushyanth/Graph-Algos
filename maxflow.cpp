#include<iostream>
using namespace std;
#include<cstdlib>
typedef struct node{
int data;
int w;
struct node *next;
}node;
void print(node *adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"->";
        node *temp=adj[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<" "<<temp->w<<"--";
            temp=temp->next;
        }cout<<endl;
    }
}
int found=1,bcap=0;
void dfs(node *adj[],int n,int parent[],int visited[],int source,int sink)
{
    if(source==sink){found=1;}
    visited[source-1]=1;
    node *temp=adj[source-1];cout<<source<<" ";
    while(temp!=NULL && found==0 )
    {
        if(visited[temp->data-1]==0 && temp->w!=0)
        {

            parent[temp->data-1]=source;
            if(temp->w < bcap)bcap=temp->w;
            dfs(adj,n,parent,visited,temp->data,sink);
            if(found==1)
            {
                node *temp1=adj[temp->data-1];
                while(temp1->data!=source)temp1=temp1->next;
                temp1->w +=bcap;
                temp->w -=bcap;
            }
        }
        temp=temp->next;
    }
}
int main()
{
  int n,e;
  cout<<"enter n and e"<<endl;
  cin>>n>>e;
  node *adj[n]={NULL};
  for(int i=0;i<e;i++)
  {
      int a,b,c;
      cin>>a>>b>>c;
      node *nn=(node *)malloc(sizeof(node));
      nn->next=NULL;
      nn->data=b;
      nn->w=c;
      node *temp=adj[a-1];
      nn->next=adj[a-1];
      adj[a-1]=nn;
    }
  for(int i=0;i<n;i++)
  {
      node *temp=adj[i];
      while(temp!=NULL)
      {
          bool isthere=false;
        node *temp1=adj[temp->data -1];
        while(temp1!=NULL && temp1->data!=i+1)temp1=temp1->next;
        if(temp1!=NULL && temp1->data==i+1)isthere=true;
        if(!isthere)
        {
            node *nn=(node *)malloc(sizeof(node));
            nn->next=NULL;
            nn->data=i+1;nn->w=0;
            nn->next=adj[temp->data-1];
            adj[temp->data-1]=nn;
        }
          temp=temp->next;
      }
  }
  //print(adj,n);
  int visited[n]={0};
  int parent[n]={0};
  int source,sink;
  cout<<endl<<"enter source and sink vertices"<<endl;
  cin>>source>>sink;int flow=0;

while(bcap!=INT_MAX && found==1)
{

    for(int j=0;j<n;j++){visited[j]=0;parent[j]=0;}
  bcap=INT_MAX;found=0;
  dfs(adj,n,parent,visited,source,sink);
  if(found==1){flow=flow + bcap;}

}//print(adj,n);
cout<<endl<<"fval :"<<flow<<endl;

}
