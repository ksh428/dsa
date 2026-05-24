#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(24);
    v.push_back(20);
    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
   // for(auto x:v)
    //{
      //  cout<<x<<" ";
    //}
    auto it=v.begin();
    cout<<*it;
}
