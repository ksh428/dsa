#include<bits/stdc++.h>
using namespace std;
int findans(int a[],int n,int sum)
{
    sort(a,a+n);
    reverse(a,a+n);
    int s=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        ans++;
        if(s>sum){
            break;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
        {cin>>a[i];
        sum+=a[i];
        }

    findans(a,n,sum);

}
