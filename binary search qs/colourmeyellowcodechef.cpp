#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


bool ispossible(int r,int b,int g,int m){
    return (r-m)+(b-m)+g>=m;

}
int color(int r,int b,int g,int n){
    int l=0;
    int ans=0;
    int u=min(n,min(r,b));
    while(l<=u){
        int mid=l+(u-l)/2;
        if(ispossible(r,b,g,mid)){
            ans=mid;
            l=mid+1;
        }else u=mid-1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){

    int n,r,g,b;
    cin>>n>>r>>g>>b;
    cout<<color(r,b,g,n)<<endl;
    }
}
