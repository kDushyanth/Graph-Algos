#include<iostream>
using namespace std;
#include<cstdlib>
typedef struct node{

int data;
struct node *l,*r;
}node;
node *bst(int pre[],int in[],int pl,int ph,int il,int ih)
{
    if(il<=ih && pl<=ph)
    {
        if(il==ih && pl==ph)
        {
            node *nn=(node *)malloc(sizeof(node));
            nn->data=pre[pl];
            nn->l=nn->r=NULL;
            return nn;
        }
        if(il<ih && pl<ph)
        {
            int i;
            for(i=il;i<=ih;i++)
            {
                if(pre[pl]==in[i])break;
            }
            node *nn=(node *)malloc(sizeof(node));
            nn->data=pre[pl];
            nn->l=nn->r=NULL;
            nn->l=bst(pre,in,pl+1,pl+i-il,il,i-1);
            nn->r=bst(pre,in,pl+i-il+1,ph,i+1,ih);
            return nn;
        }
    }
    return NULL;
}
void post(node *root)
{
    if(root!=NULL)
    {
        post(root->l);
        post(root->r);
        cout<<root->data<<" ";
    }

}
node *searc(node *root,int key)
{
    if(root==NULL || root->data==key)return root;
    if(root->data < key)return searc(root->r,key);
    if(root->data > key)return searc(root->l,key);
}
node *ist(node *root,int key)
{
    if(root==NULL)
    {
        node *nn=(node *)malloc(sizeof(node));
        nn->data=key;
        nn->l=nn->r=NULL;
        return nn;
    }
    if(root->data <key)root->r=ist(root->r,key);
    if(root->data >key)root->l=ist(root->l,key);
    return root;
}
node *del(node *root ,int key)
{
    if(root==NULL)
        return root;
    if(root->data <key)root->r=del(root->r,key);
    else{
        if(root->data > key)root->l=del(root->l,key);
        else{
            if(root->l!=NULL && root->r!=NULL)
            {
                node *temp=root->r;
                while(temp->l!=NULL)
                {
                    temp=temp->l;
                }
                root->data=temp->data;
                root->r=del(root->r,temp->data);
                return root;
            }
            node *t=(root->l!=NULL)?root->l:root->r;
            free(root);
            return t;

        }
    }
    return root;
}
int hei(node *root)
{
    if(root==NULL)return -1;
    int x=hei(root->l);
    int y=hei(root->r);
    return x>y? x+1:y+1;
}
int main()
{
    int n;
    cin>>n;
    int pre[n];int in[n];
    for(int i=0;i<n;i++)cin>>pre[i];
    for(int i=0;i<n;i++)cin>>in[i];
    node *root=NULL;
    root=bst(pre,in,0,n-1,0,n-1);
    //post(root);
    int key;
    cin>>key;
   root=ist(root,key);
post(root);
root=del(root,key);
post(root);
cout<<endl;
cout<<hei(root);
}
