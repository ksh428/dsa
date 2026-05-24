#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>a;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_set<int>s;
    int sum=0;
    for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==0 || s.find(sum)!=s.end()) cout<<"yes";
            s.insert(sum);


    }
    cout<<"false";
    }
