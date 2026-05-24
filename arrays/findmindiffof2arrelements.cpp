//find the min diff b/w 2 array elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    sort(v1.begin(),v1.end());
    vector<int> v2;
    for(int i=0;i<n;i++){
        v2.push_back(v1[i+1]-v1[i]);
    }
    sort(v2.begin(),v2.end());
    cout<<v2[0];

}

