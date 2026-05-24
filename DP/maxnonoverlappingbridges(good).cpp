#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;

}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>bridges; //n,s
    for(int i=0;i<n;i++){
        int n,s;
        cin>>n>>s;
        bridges.push_back({n,s});
    }
    sort(bridges.begin(),bridges.end(),compare);
    //lis at south
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(bridges[j].second<bridges[i].second){
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }
    int maxval=0;
    for(int x:lis){
        if(x>maxval) maxval=x;
    }
    cout<<maxval<<endl;


}
