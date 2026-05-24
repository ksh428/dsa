//DP+TRIE

class Solution {
    //normal approach is n*l^3*logn
public:
    struct Node {
  Node* links[26];
  int f = 0;
};
void insert(string s, Node* root) {
  Node * node = root;
  for (int i = s.size()-1; i>=0; i--) {
    if (node->links[s[i] - 'a'] == NULL) {
      node->links[s[i] - 'a'] = new Node();
    }
    node = node->links[s[i] - 'a'];
  }
  node->f += 1;
  //node->w = s;
}
    static bool cmp(string a,string b){
        return a.size()<b.size();
    }
    //always insert the word in rveerse
    //usingtrie substr becomes o(1)

    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        sort(w.begin(),w.end(),cmp);
        int n=w.size();
        Node* root=new Node();
        vector<string>ans;
        for(string s:w){
            if(s.size()==0) continue;
            vector<int>dp(s.size()+1,0);
            dp[0]=1;
            for(int i=0;i<s.size();i++){
                Node* curr=root;
                for(int j=i;j>=0;j--){
                    if(!curr->links[s[j]-'a']) break;
                    curr=curr->links[s[j]-'a'];
                    if(dp[j] and curr->f){
                        dp[i+1]=1;
                        break;
                    }
                }
            }
            if(dp[s.size()]) ans.push_back(s);
            insert(s,root);
        }
        return ans;
    }
};
