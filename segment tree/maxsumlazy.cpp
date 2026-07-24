#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int a[MAXN];
int seg[4 * MAXN];
int lazy[4 * MAXN];

void build(int ind,int l,int h)
{
    if(l==h)
    {
        seg[ind]=a[l];
        return;
    }
    int m=(l+h)/2;
    build(2*ind+1,l,m);
    build(2*ind+2,m+1,h);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void pointupdate(int ind,int l,int h,int node,int val)
{
    if(l==h)
    {
        seg[ind]+=val;
        return;
    }
    if(node<l or node>h) return;
    int m=(l+h)/2;
    if(node>=l and node<=m) pointupdate(2*ind+1,l,m,node,val);
    else pointupdate(2*ind+2,m+1,h,node,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void rangeupdate(int ind,int l,int h,int ql,int qh,int val)
{
    if(lazy[ind]!=0)
    {
        seg[ind]+=lazy[ind];
        if(l!=h)
        {
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l>qh or h<ql) return ;
    if(l>=ql and h<=qh)
    {
        seg[ind]+=(h-l+1)*val;
        if(l!=h)
        {
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }
    }
    int m=(l+h)/2;
    rangeupdate(2*ind+1,l,m,ql,qh,val);
    rangeupdate(2*ind+2,m+1,h,ql,qh,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    
}
int query(int ind,int l,int h,int ql,int qh)
{
    if(l>qh or h<ql) return 0;
    if(l>=ql and h<=qh)
    {
        return seg[ind];
    }
    int m=(l+h)/2;
    int left=query(2*ind+1,l,m,ql,qh);
    int right=query(2*ind+2,m+1,h,ql,qh);
    return left+right;
}
int queryrange(int ind,int l,int h,int ql,int qh)
{
    if(lazy[ind]!=0)
    {
        seg[ind]+=lazy[ind];
        if(l!=h)
        {
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l>qh or h<ql) return 0;
    if(l>=ql and h<=qh)
    {
        return seg[ind];
    }
    int m=(l+h)/2;
    int left=query(2*ind+1,l,m,ql,qh);
    int right=query(2*ind+2,m+1,h,ql,qh);
    return left+right;
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n - 1);

    // Example
    rangeUpdate(0, 0, n - 1, 1, 3, 5);

    cout << query(0, 0, n - 1, 0, 4) << '\n';

    return 0;
}