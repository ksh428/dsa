class Solution {
public:
     struct Node{
        Node* links[26];
        int f=0;
        string w="";
    };
    void insert(string s,Node* root){
        Node * node=root;
        for(int i=0;i<s.size();i++){
          if(node->links[s[i]-'a']==NULL){
              node->links[s[i]-'a']=new Node();
          }
            node=node->links[s[i]-'a'];
        }
        node->f+=1;
        node->w=s;
    }
    string query(string s,Node* root){
        Node* curr=root;
        for(int i=0;i<s.size();i++){
            if(curr->f>0) return curr->w;
            if(curr->links[s[i]-'a']==NULL){
                if(curr->f>0){
                    return curr->w;
                }else return s;
            }else curr=curr->links[s[i]-'a'];
        }
        return s;
    }
    string replaceWords(vector<string>& d, string s) {
        Node* root=new Node();
        for(string s:d){
            insert(s,root);
        }
        string t=s;
        stringstream str(s);
        string w;
        string ans="";
        while(str>>w){
            string s=query(w,root);
            ans+=s;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};
