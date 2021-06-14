#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct no{
int v;
int key;
}no;
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
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
}
void swa(no k[],int idx[],int a,int b)
{
    int t=idx[k[a].v-1];
    idx[k[a].v-1]=idx[k[b].v-1];
    idx[k[b].v-1]=t;
    no t1;
    t1.v=k[a].v;
    t1.key=k[a].key;
    k[a].v=k[b].v;
    k[a].key=k[b].key;
    k[b].v=t1.v;
    k[b].key=t1.key;
}
void movedown(no k[],int idx[],int n1,int i)
{
    int mi=i;
    int l=2*i+1,r=2*i+2;
    if(l<n1 && k[mi].key > k[l].key)mi=l;
    if(r<n1&& k[mi].key >k[r].key)mi=r;
    if(mi!=i)
    {
        swa(k,idx,mi,i);
        movedown(k,idx,n1,mi);
    }
}
no ext(no k[],int idx[],int *n1)
{
    no t=k[0];int in=k[0].v;
    swa(k,idx,0,*n1-1);
    *n1=*n1-1;
    movedown(k,idx,*n1,0);
    idx[in-1]={-1};
    return t;
}
 void moveup(no k[],int idx[],int n1,int i)
 {
     int p=(i-1)/2;
     if(p>=0 && k[p].key > k[i].key)
     {
         swa(k,idx,i,p);
         moveup(k,idx,n1,p);
     }
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
    //print(adj,n);
    no k[100];int n1=n;
    int idx[100]={-1};
    for(int i=0;i<n1;i++)
    {
        k[i].key=INT_MAX;
        k[i].v=i+1;
        idx[i]=i;
    }
   int source;cin>>source;
    k[idx[source-1]].key=0;
    int parent[n1]={-1};
    int coun=n;
    while(coun--)
    {
      no t=ext(k,idx,&n1);
      node *temp=adj[t.v-1];
      while(temp!=NULL)
      {
          if(idx[temp->data-1]!=-1 && temp->w +k[idx[t.v-1]].key < k[idx[temp->data-1]].key)
          {
              k[idx[temp->data-1]].key=temp->w+k[idx[t.v-1]].key;
              moveup(k,idx,n1,idx[temp->data-1]);
              parent[temp->data-1]=t.v;
          }
          temp=temp->next;
      }
    }
  for(int i=0;i<n;i++)
  {
      cout<<i+1<<" "<<parent[i]<<endl;
  }
}
