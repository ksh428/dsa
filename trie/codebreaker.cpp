//offline queries
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct Node {
  Node* links[26];
  int f = 0;
};
void insert(string s, Node* root) {
  Node * node = root;
  for (int i = 0; i < s.size(); i++) {
    if (node->links[s[i] - 'a'] == NULL) {
      node->links[s[i] - 'a'] = new Node();
    }
    node = node->links[s[i] - 'a'];
  }
  node->f += 1;
}
string query(Node* root,string s){
      Node* curr=root;
      string ans="";
      for(int i=0;i<s.size();i++){
            if(curr->links[s[i]-'a']!=NULL){
                  ans+=s[i];
                  curr=curr->links[s[i]-'a'];
            }else break;
      }
      if(curr->f>0){
            return ans;
      }
      for(int i=0;i<26;i++){
            if(curr->links[i]!=NULL){
                  ans+=char(i+'a');
                  curr=curr->links[i];
                  i=-1;
                  if(curr->f>0){
                        return ans;
                  }
            }
      }
      return ans;
}

void solve() {
      int n;
      cin>>n;
      Node* root=new Node();
      vector<string>a(n+1);
      for(int i=1;i<=n;i++){
            cin>>a[i];
      }
      int q;
      cin>>q;
      vector<pair<string,int>>v[n+1];//string,query at v[r]
      for(int i=1;i<=q;i++){
            int r;
            string s;
            cin>>r>>s;
            v[r].push_back({s,i});
      }
      string ans[q+1];
      for(int i=1;i<=n;i++){
            insert(a[i],root);
            int sz=v[i].size();
            for(int j=0;j<sz;j++){
                  string curr=query(root,v[i][j].first);
                  ans[v[i][j].second]=curr;
            }
      }
      for(int i=1;i<=q;i++){
            cout<<ans[i]<<endl;
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
