#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int n;
    ll w,l;
    cin>>n>>w>>l;
   int h[n],r[n];
    for(int i=0;i<n;i++){
        cin>>h[i]>>r[i];
    }
    int t=0;
    int sum=0;
    for(int i=0;i<n;i++){
        int hgh=h[i]+r[i]*t;
        if(hgh>=l){
            sum+=hgh;
        }
        if(sum>=w){
            cout<<t;
            break;
        }
        t++;
    }

}
