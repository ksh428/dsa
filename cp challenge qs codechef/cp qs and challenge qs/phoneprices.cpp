#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int c=1;
        for(int i=1;i<n;i++)
        {
            if((i-5)>0)
            {
                if(a[i]<a[i-1] && a[i]<a[i-2] && a[i]<a[i-3] && a[i]<a[i-4] && a[i]<a[i-5])
                    c++;
            }
        }
        cout<<c<<endl;
    }
}
