#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    int c=0;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0') a--;
        if(s[i]=='1') b--;
        if(s[i]=='?') c++;
    }
    // cout<<"in "<<a<<" "<<b<<"\n";
    if(c==0){
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                cout<<-1<<"\n";
                return;
            }
        }
        if(a>0 || b>0){
            cout<<-1<<"\n";
            return;
        }
        cout<<s<<"\n";
        return;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]=='?' && s[n-i-1]!='?'){
            if(s[n-i-1]=='0' && a>0){
                s[i]='0';
                a--;
            }
            else if(s[n-i-1]=='0' && a==0){
                cout<<-1<<"\n";
                return;
            }
            else if(s[n-i-1]=='1' && b>0){
                s[i]='1';
                b--;
            }
            else{
                cout<<-1<<"\n";
                return;
            }
        }
        else if(s[n-i-1]=='?' && s[i]!='?'){
            if(s[i]=='0' && a>0){
                s[n-i-1]='0';
                a--;
            }
            else if(s[i]=='0' && a==0){
                cout<<-1<<"\n";
                return;
            }
            else if(s[i]=='1' && b>0){
                s[n-i-1]='1';
                b--;
            }
            else{
                cout<<-1<<"\n";
                return;
            }
        }
    }
    for(int i=0;i<n/2;i++){
        if(s[i]=='?' && s[n-i-1]=='?'){
            if(a>=2) s[i]='0' , s[n-i-1]='0' , a-=2;
            else if(b>=2) s[i]='1' , s[n-i-1]='1' , b-=2;
            else{
                cout<<-1<<"\n";
                return;
            }
        }
    }
    if(n%2==1 && s[n/2]=='?'){
        if(a>0) s[n/2]='0', a--;
        else if(b>0) s[n/2]='1' , b--;
        else{
            cout<<-1<<"\n";
            return;
        }
    }
    if(a>0 || b>0){
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<s<<"\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";
                solve();
    }
    return 0;
}


