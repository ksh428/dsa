
// normal sorting using merge sort and stl o(nlogn)
//sorting using hashing and 2 separateloops o(n)


//efficient soln


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int f,s;
    f=s=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<f)
        {
            s=f;
            f=a[i];
        }
        else if(a[i]<s && a[i]!=f)
        {
            s=a[i];
        }
    }
    cout<<f<<s;
}
