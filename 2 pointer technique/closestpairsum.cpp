#include<bits/stdc++.h>
// for 2 sorted arrays
using namespace std;
int main()
{
    int a[]={1,4,5,7};
    int b[]={10,20,30,40};
    int x;
    cin>>x;
    int l=0;int r=3;//n-1
    int lres,rres,diff;
    diff=INT_MAX;
    while(l<4 && r>=0)
    {
        if(abs(a[l]+b[r]-x)<diff)
        {
            lres=a[l];
            rres=b[r];
            diff=abs(a[r]+b[l]-x);

        }
        else if(a[l]+b[r]>x)
            r--;
        else l++;
    }
    cout<<lres<<" "<<rres;


}
