// application of prefix sum
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int s=0;
    //method 1
   for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    int rs=s;
    int ls=0;
    for(int i=0;i<n;i++)
    {
        rs-=a[i];
        if(ls==rs)
            {cout<<i;
            break;}
        ls+=a[i];

    }




}
