Node* findlca(Node* root,int a,int b){
    if(!root) return NULL;
    if(root->data==a || root->data==b) return root;
    Node* llca=findlca(root->left,a,b);
    Node* rlca=findlca(root->right,a,b);
    if(llca && rlca) return root;
    if(llca) return llca;
    else return rlca;
}
int dist(Node* root,int val,int level){//finds level
    if(!root) return 0;
    if(root->data==val) return level;
    int lvl=dist(root->right,val,level+1);
    if(lvl!=0) return lvl;
    lvl=dist(root->left,val,level+1);
    return lvl;

}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* lca=findlca(root,a,b);
    int dl=dist(lca,a,0);
    int dr=dist(lca,b,0);
    return dl+dr;
}
