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
  //node->w = s;
}
bool query1(string s,Node*root){
    Node* curr=root;
    for(char c:s){
        if(curr->links[c-'a']==NULL) return 0;
        else curr=curr->links[c-'a'];
    }
    return curr->f;
}
vector<string>ans;
void dfs(Node* curr,string s){
    if(curr->f>0){
        ans.push_back(s);
    }
    for(int i=0;i<26;i++){
        if(curr->links[i]){
            string news=s+char(i+'a');
            dfs(curr->links[i],news);
        }
    }
}
void query(string s,Node* root){
    Node* curr=root;
    int i;
    for(i=0;i<s.size();i++){
        if(curr->links[s[i]-'a']==NULL){
            break;
        }else curr=curr->links[s[i]-'a'];
    }
    string t=s.substr(0,i);
    //cout<<t<<endl;
    dfs(curr,t);
}
vector<string> spellChecker(vector<string> &d, string &q){
    ans.clear();
    Node* root=new Node();
    for(string s:d){
        insert(s,root);
    }
    if(query1(q,root)){
        return {};
    }
    query(q,root);
    return ans;



}
