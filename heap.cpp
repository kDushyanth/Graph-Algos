#include<iostream>
using namespace std;
void swa(int a1[],int a,int b)
{
    int t;
    t=a1[a];
    a1[a]=a1[b];
    a1[b]=t;
}
void movedown(int a[],int n,int i)
{
    int ma=i;
    int l=2*i+1,r=2*i+2;
    if(l<n && a[ma]<a[l])ma=l;
    if(r<n && a[ma]<a[r])ma=r;
    if(ma!=i)
    {
        swa(a,i,ma);
        movedown(a,n,ma);
    }
}
void buildma(int a[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        movedown(a,n,i);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        swa(a,0,i);
        n--;
        movedown(a,n,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    buildma(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    heapsort(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
