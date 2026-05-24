
class StreamChecker {
public:
    struct Node{
        Node* links[26];
        int f=0;
    };
    Node* root;
    string ans;
    void insert(string s, Node* root) {
      Node * node = root;
      for (int i = s.size()-1; i>=0; i--) {
        if (node->links[s[i] - 'a'] == NULL) {
          node->links[s[i] - 'a'] = new Node();
        }
        node = node->links[s[i] - 'a'];
      }
      node->f += 1;
    }
    StreamChecker(vector<string>& words) {
        root=new Node();
        ans="";
        for(string s:words){
            insert(s,root);
        }
    }

    bool query(char c) {
        ans+=c;
        Node* curr=root;
        for(int i=ans.size()-1;i>=0;i--){
            curr=curr->links[ans[i]-'a'];
            if(!curr) return 0;
            if(curr->f) return 1;
        }
        return 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
