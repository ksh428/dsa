
#include<bits/stdc++.h>
using namespace std;
vector<string>v;

//pick not pick
void findsub(string s,string ans){
    if(s.size()==0){
        v.push_back(ans);
        return;
    }
    findsub(s.substr(1),ans+s[0]);
    findsub(s.substr(1),ans);
}

int main(){

    string s;
    cin>>s;
    findsub(s,"");
    for(auto x:v) cout<<x<<" ";
}
