
#include <bits/stdc++.h>
using namespace std;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++) v.push_back({price[i],i+1});
    sort(v.begin(),v.end());
    int ans=0;
    int rem=k;
    for(auto j:v){
        if(rem>=((j.first)*(j.second))){
            ans+=j.second;
            rem-=j.first*j.second;
        }else{
            int no=rem/j.first;
            ans+=no;
            rem-=j.first*no;
        }
    }
    return ans;

}

