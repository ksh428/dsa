
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        int s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]>k){
                a[i]=k;
            }
        }
        int s1=0;
        for(int x:a){
            s1+=x;

        }
        cout<<s-s1<<endl;

    }

}
