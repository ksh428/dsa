#include <bits/stdc++.h>
using namespace std;
int a[1001];
int seg[4001];
int lazy[4001];

void build(int ind,int l,int r)
{
    if(l==r)
    {
        seg[ind]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*ind+1,l,m);
    build(2*ind+2,m+1,r);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
};
void pointupdate(int ind,int l,int r,int node,int val)
{
    if(l>=node and r<=node)
    {
        seg[ind]=val;
        return;
    }
    if(node<l or node>r) return;
    int m=(l+r)/2;
    if(node>=l and node<=m) pointupdate(2*ind+1,l,m,node,val);
    else pointupdate(2*ind+2,m+1,r,node,val);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
void rangeupdate(int ind,int l,int r,int ql,int qr,int val)
{
    if(lazy[ind]!=0)
    {
        seg[ind]=lazy[ind];
        if(l!=r)
        {
            lazy[2*ind+1]=lazy[ind];
            lazy[2*ind+2]=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(qr<l or ql>r) return;
    if(l>=ql and r<=qr)
    {
        seg[ind]=val;
        if(l!=r)
        {
            lazy[2*ind+1]=val;
            lazy[2*ind+2]=val;
        }
        return;
    }
    int m=(l+r)/2;
    rangeupdate(2*ind+1,l,m,ql,qr,val);
    rangeupdate(2*ind+2,m+1,r,ql,qr,val);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int l,int r,int ql,int qr)
{
    if(qr<l or ql>r) return 0;
    if(l>=ql and r<=qr) return seg[ind];
    int m=(l+r)/2;
    int o1=query(2*ind+1,l,m,ql,qr);
    int o2=query(2*ind+2,m+1,r,ql,qr);
    return max(o1,o2);
}
int queryrange(int ind,int l,int r,int ql,int qr)
{
    if(lazy[ind]!=0)
    {
        seg[ind]=lazy[ind];
        if(l!=r)
        {
            lazy[2*ind+1]=lazy[ind];
            lazy[2*ind+2]=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l>qr or r<ql) return 0;
    if(l>=ql and r<=qr) return seg[ind];
    int m=(l+r)/2;
    int o1=queryrange(2*ind+1,l,m,ql,qr);
    int o2=queryrange(2*ind+2,m+1,r,ql,qr);
    return max(o1,o2);
}

int main() {
	int n;
	build(0,0,n-1);

}
