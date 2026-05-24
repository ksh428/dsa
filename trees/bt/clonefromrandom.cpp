//try1

class Solution{
  public:
    unordered_map<Node*,Node*>m;
    void saverand(Node* root){
        if(!root) return ;
            m[root]=root->random;
        saverand(root->left);
        saverand(root->right);
    }
    Node* makenew(Node* root){
        if(!root) return NULL;
        Node* curr=new Node(root->data);
        curr->left=makenew(root->left);
        curr->right=makenew(root->right);
        return curr;
    }
    void finalize(Node* &root){
        if(!root) return NULL;
        if(m[root]) root->random=m[root];
        finalize(root->left);
        finalize(root->right);
    }
    Node* cloneTree(Node* root)
    {
       saverand(root);
       Node* newtree=makenew(root);
        finalize(newtree);
        return newtree;
    }
};

//working
class Solution{
  public:
    Node* solve1(Node* root,unordered_map<Node*,Node*>&m){
        if(!root) return NULL;
        m[root]=new Node(root->data);
        m[root]->left=solve1(root->left,m);
        m[root]->right=solve1(root->right,m);
        return m[root];
    }
    void connect(Node* root,unordered_map<Node*,Node*>&m){
        if(!root) return;
        m[root]->random=m[root->random];
        connect(root->left,m);
        connect(root->right,m);
    }
    Node* cloneTree(Node* root)
    {
       unordered_map<Node*,Node*>m;
       Node* newroot=solve1(root,m);
       connect(root,m);
       return newroot;
    }
};
