#include<bits/stdc++.h>
usoing namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    int M=0,c=0;
    for(int i=0;;i<n-1;i++)
    {
        if(a[i]>M)
        {
            M=a[i];
            if(i)
            c=1;
        }
        else{
            c++;
        }
    }
    if(c>=k)
        cout<<M;
}
