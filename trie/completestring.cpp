struct Node{
    Node* links[26];
    bool flag=false;
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(!node->links[s[i]-'a']!=NULL){
                node->links[s[i]-'a']=new Node();
            }
            node=node->links[s[i]-'a'];
        }
        node->flag=true;
    }
    bool ok(string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(node->links[s[i]-'a']!=NULL){
                node=node->links[s[i]-'a'];
                if(node->flag==false){
                    return false;
                }else continue;
            }else return false;
        }
        return true;
    }

};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(int i=0;i<a.size();i++){
        trie.insert(a[i]);
    }
    string ans="";
    for(auto it:a){
        if(trie.ok(it)){
            if(it.size()>ans.size()){
                ans=it;
            }else if(it.size()==ans.size()){
                if(it<ans){
                    ans=it;
                }
            }
        }
    }





    return (ans=="")?"None":ans;
}
