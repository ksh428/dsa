struct Node{
    Node* links[26];
    int cp=0;
    int ew=0;
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void increaseend(){
        ew++;
    }
    void increaseprefix(){
        cp++;
    }
    void deleteend(){
        ew--;
    }
    void deleteprefix(){
        cp--;
    }
};
class Trie{
    private:
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseend();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }else {
                return 0;
            }
        }
        return node->ew;
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->cp;
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
                node->cp--;
            }else return ;
        }
        node->ew--;
    }
};

