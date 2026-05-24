
//USING SLIDING WINDOW
//Maximum Size SubArray sum Of Size K
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=INT_MIN;
    int wsum=0;
    for(int i=0;i<k;i++){
        wsum+=a[i];
    }

    for(int j=k;j<n;j++){
        ans=max(ans,wsum);
        wsum+=a[j];
        wsum-=a[j-k];
        //ans=max(ans,wsum);
    }
    cout<<ans;

}
