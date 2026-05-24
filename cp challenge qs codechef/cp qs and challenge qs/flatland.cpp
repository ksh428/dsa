#include<iostream>
using namespace std;
int main()
{
    int a[33]={0};
    for(int i=1;i<33;i++)
    {
       a[i]+=i*i ;
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        while(n!=0)
        {
            for(int i=1;i<33;i++)
            {
                if(a[i]<=n && a[i+1]>n)
                {
                    n=n-a[i];c++;
                }
            }
        }
        cout<<c<<endl;

    }
}
