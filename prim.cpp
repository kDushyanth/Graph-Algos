#include<bits/stdc++.h>
using namespace std;
#include<cstdlib>
typedef struct node{
int d;
struct node *next;
int w;
}node;
typedef struct no{
int v;
int key;
}no;
void swa(no ke[],int idx[],int i,int mi)
{
    int t=idx[ke[i].v-1];
    idx[ke[i].v-1]=idx[ke[mi].v-1];
    idx[ke[mi].v-1]=t;
    no t1;
    t1.v=ke[i].v;
    ke[i].v=ke[mi].v;
    ke[mi].v=t1.v;
    t1.key=ke[i].key;
    ke[i].key=ke[mi].key;
    ke[mi].key=t1.key;
}
void movedown(no ke[],int idx[],int n,int i)
{
    int mi=i;int l=2*i+1,r=2*i+2;
    if(l<n && ke[mi].key>ke[l].key)mi=l;
    if(r<n && ke[mi].key>ke[r].key)mi=r;
    if(mi!=i)
    {
        swa(ke,idx,i,mi);
        movedown(ke,idx,n,mi);
    }
}
void buildmi(no ke[],int idx[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
        movedown(ke,idx,n,i);
}
int  ext(no ke[],int idx[],int *n1)
{

    int mi=ke[0].v;
    swa(ke,idx,0,*n1-1);
    (*n1)--;idx[ke[*n1].v]=-1;
    movedown(ke,idx,*n1,0);
    return mi;
}
void print(node *adj[],int n)
{
 for(int i=0;i<n;i++)
 {
     cout<<i+1<<"->";
     node *temp=adj[i];
     while(temp!=NULL)
     {
         cout<<temp->d<<","<<temp->w<<" ";
         temp=temp->next;
     }cout<<endl;
 }
}
void moveup(no ke[],int idx[],int i)
{
    int p=(i-1)/2;
    if(p>=0 && ke[p].key>ke[i].key)
    {
        swa(ke,idx,i,p);
        moveup(ke,idx,p);
    }

}
int main()
{
    int n,e;cout<<"enter n and e"<<endl;cin>>n>>e;
    node *adj[n]={NULL};
    for(int i=0;i<e;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        node *nn=(node *)malloc(sizeof(node));
        nn->d=a;nn->next=NULL;nn->w=c;
        node *temp1=adj[b-1];
        if(temp1==NULL)adj[b-1]=nn;
        else
        {
            while(temp1->next!=NULL)temp1=temp1->next;
            temp1->next=nn;
        }
         node *nn1=(node *)malloc(sizeof(node));
        nn1->d=b;nn1->next=NULL;nn1->w=c;
        node *temp2=adj[a-1];
        if(temp2==NULL)adj[a-1]=nn1;
        else
        {
            while(temp2->next!=NULL)temp2=temp2->next;
            temp2->next=nn1;
        }
    }
    int n1=n;
    print(adj,n);
 no ke[100];
 for(int i=0;i<n;i++)
 {
     ke[i].v=i+1;
     ke[i].key=INT_MAX;
 }
 ke[0].key=0;
 int idx[n];
 buildmi(ke,idx,n1);
 for(int i=0;i<n1;i++)
 {
     cout<<ke[i].key<< " "<<ke[i].v<<endl;
 }
 for(int i=0;i<n;i++)
 {
     idx[i]=i;
 }
 //cout<<ext(ke,idx,&n1);
int coun=n;
 while(coun--)
 {
     int u=ext(ke,idx,&n1);cout<<u<<" ";
     node *temp=adj[u-1];
     while(temp!=NULL)
     {
         if(idx[temp->d-1]!=-1 && temp->w <ke[idx[temp->d-1]].key)
         {
             ke[idx[temp->d-1]].key=temp->w;
             moveup(ke,idx,idx[temp->d-1]);
         }
         temp=temp->next;
     }
 }

}
