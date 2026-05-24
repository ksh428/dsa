#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int a[256]={0};
    int i,r;
    i=r=0;
    string ans="";
    while(i<n){
        if(a[s[i]]==0){
            a[s[i]]=1;
            ans+=s[i];
        }
        i++;
    }
    cout<<ans;

}
