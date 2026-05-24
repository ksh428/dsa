#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int remem,k;
        int index;
        int a[n+1];
        for(int i=0;i<n+1;i++)
        {
            cin>>a[i];
        }
        cin>>k;
        remem=a[k-1];
        sort(a,a+n);   // or use vector if compilation error
        for(int i=0;i<n+1;i++)
        {

            if(a[i]==remem)
                index =i+1;
                break;
        }
        cout<<index<<endl;


    }
}
