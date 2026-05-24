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
	string s;
	cin>>s;
	int k;
	cin>>k;
	unordered_map<char,int>m;
	int len=0;
	int i=0,j=0;
	while(1){
	      bool f1=0,f2=0;
	      while(j<n){
	            m[s[j]]++;
	            if(m.size()<=k){
	                  len=max(len,j-i);
	            }else break;
	            f1=1;
	      }
	      while(i<j){
	            if(m[s[i]]==1){
	                  m.erase(s[i]);
	            }else m[s[i]]--;

	            if(m.size()<=k) break;
	             i++;
	             f2=1;
	      }
	}
	cout<<len;
}
