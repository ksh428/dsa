#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int cneg=0;
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            cneg++;
    }
    sort(a,a+n);

    if(cneg==k)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]<0)
                a[i]*=-1;
        }
    }
    else if(cneg>k){
        for(int i=0;i<k;i++)
        {
            a[i]*=-1;
        }

    }
    else{
        int rem;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0)
            {
                a[i]*=-1;
            }

        }
         rem=k-cneg;
        // all elements are now positive
        sort(a,a+n);
        for(int i=0;i<rem;i++)
        {
            a[0]*=-1;}
    }

    int sum=0;
    for(int x:a)
    {
        sum+=x;
    }
    cout<<sum<<endl;

}

