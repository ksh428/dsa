#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
   // int b[3]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //b[a[i]]++;
    }
    multiset<int>s;
    for(int x:a)
    {
        s.insert(x);
    }
    for(int p:s)
    {
        cout<<p<<" ";
    }
   /* for(int i=0;i<3;i++)
    {
        while(b[i]--)
        {
            cout<<i<<" ";
        }
    }
    */


}
