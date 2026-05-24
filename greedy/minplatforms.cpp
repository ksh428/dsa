
// 2 pointer method ....
#include<bits/stdc++.h>
using namespace std;
int findminplat(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1;
    int j=0;
    int res=1;
    int p=1;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            p++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            p--;
            j++;
        }
        if(p>res)
            res=p;
    }
    cout<<res<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>dep[i];
    }
    findminplat(arr,dep,n);

}
