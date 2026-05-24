#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<n;j++)
        {
            cin>>b[j];
        }
        //sorting in array
        sort(a,a+n);
        sort(b,b+n);
        int suma=0,sumb=0;
        for(int i=0;i<n-1;i++)
        {
            suma+=a[i];
            sumb+=b[i];
        }
        suma>sumb?cout<<"ALICE":cout<<"BOB";

    }
}

