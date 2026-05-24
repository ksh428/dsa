#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[20]={0};
    a[1]=a[2]=1;
    for(int i=3;i<20;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    int b[n+1]={0};
    for(int i=1;i<20;i++)
    {
        if(a[i]<=n)
        {
            b[a[i]]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]>0)
            cout<<"O";
        else
            cout<<"o";
    }
}
