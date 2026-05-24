/* Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10 */


#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct Node{
      Node* links[26];
      int maxpref=0;
      int f=0;
};
void insert(string s,int w,Node* root){
      Node* node=root;
      for(int i=0;i<s.size();i++){
            if(!node->links[s[i]-'a']){
                node->links[s[i]-'a']=new Node();
            }
            node=node->links[s[i]-'a'];
            node->maxpref=max(w,node->maxpref);
      }
      node->f=1;
}
int query(string s,Node* root){
      Node* node=root;
      for(int i=0;i<s.size();i++){
            if(!(node->links[s[i]-'a'])){
                  return -1;
            }else{
                  node=node->links[s[i]-'a'];
            }
      }
      if(node->f==1) return -1;
      return node->maxpref;
}

void solve() {
      int n,q;
      cin>>n>>q;
      //map<string,int>mp;

      Node* root=new Node();
      for(int i=0;i<n;i++){
            string s;
            int no;
            cin>>s>>no;
           // mp[s]++;
            insert(s,no,root);

      }

      while(q--){
            string t;
            cin>>t;
            int ans=query(t,root);
            cout<<ans<<endl;

      }


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      solve();
	return 0;
}
