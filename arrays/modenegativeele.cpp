
//multiple elemenys mah be mode
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={-1,-1,2,2,2,-1,0,0};
    int n=8;
    unordered_map<int,int>m;
    for(int x:a){
        m[x]++;
    }
    int mf=-1;
    vector<int>res;
    for(auto p:m){
        if(p.second>mf){
            mf=p.second;
            res={p.first};
        }else if(p.second==mf) res.push_back(p.first);
    }
    for(int x:res) cout<<x<<" ";
}

