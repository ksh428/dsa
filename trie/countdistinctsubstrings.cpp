struct Node{
    Node* links[26];
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
        for(int i=0;i<26;i++){
            root->links[i]=NULL;
        }
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(root->links[i]!=NULL) delete root->links[i];
        }
        delete root;
    }
    void insert(string s,int &ans){

        for(int i=0;i<s.size();i++){
             Node* node=root;
            for(int j=i;j<s.size();j++){
                if(!node->links[s[j]-'a']!=NULL){
                    ans++;
                    node->links[s[j]-'a']=new Node();
                }
                node=node->links[s[j]-'a'];
            }
        }
        ans++;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie trie;
    int ans=0;
    trie.insert(s,ans);
    return ans;
}
