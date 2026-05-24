#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
void solve(){

}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      int n;
      cin>>n;
      unordered_map<string,string>m;
      while(n--){
            string s,d;
            cin>>s>>d;
            m[s]=d;
      }
      unordered_map<string,bool> fs;
      for(auto it:m){
            fs[it.second]=0;
            if(fs.find(it.first)==fs.end()) fs[it.first]=1;
      }
      string src="";

      for(auto it:fs){
           if(it.second){
                 src=it.first;
                 break;
           }
      }
      while(1){
            if(m.find(src)!=m.end()){
                  cout<<src<<" -> ";
                  src=m[src];
            }else{
                  cout<<src<<".";
                  break;
            }
      }
}
