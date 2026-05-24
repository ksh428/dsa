
class Solution {
  public:
  map<Node*,Node*>mp;
  void getpar(Node* root){
      if(!root) return;
      if(root->left) mp[root->left]=root;
      if(root->right) mp[root->right]=root;
      getpar(root->left);
      getpar(root->right);
  }
  Node* temp=NULL;
  void mark(Node* root,int t){
      if(!root) return;
      if(root->data==t) {
          temp=root;
          return;
      }
      mark(root->left,t);
      mark(root->right,t);
  }
    int minTime(Node* root, int t)
    {
        getpar(root);
        queue<pair<int,Node*>>q;
        set<Node*>st;
        mark(root,t);
        int currtime=0;;
        q.push({0,temp});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
             currtime=curr.first;
            Node* curroot=curr.second;
            if(curroot->left and st.find(curroot->left)==st.end()) q.push({currtime+1,curroot->left}),st.insert(curroot->left);
            if(curroot->right and st.find(curroot->right)==st.end()) q.push({currtime+1,curroot->right}),st.insert(curroot->right);
            if(mp.find(curroot)!=mp.end() and st.find(mp[curroot])==st.end()){
                q.push({currtime+1,mp[curroot]});
                st.insert(mp[curroot]);
            }
        }
        return currtime;

