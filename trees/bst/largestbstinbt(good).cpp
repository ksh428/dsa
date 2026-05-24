
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};

info solve(Node* root){
    if(!root) return {0,INT_MIN,INT_MAX,0,true};//learn
    if(root->left==NULL and root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    info linfo=solve(root->left);
    info rinfo=solve(root->right);
    info curr;
    curr.size=1+linfo.size+rinfo.size;
    if(linfo.isbst and rinfo.isbst and linfo.max<root->data and rinfo.min>root->data){
        curr.min=min(linfo.min,min(rinfo.min,root->data));
        curr.max=max(linfo.max,max(rinfo.max,root->data));
        curr.ans=curr.size;
        curr.isbst=1;
        return curr;
    }
    curr.min=min(linfo.min,min(rinfo.min,root->data));
        curr.max=max(linfo.max,max(rinfo.max,root->data));
        curr.ans=max(linfo.ans,rinfo.ans);
        curr.isbst=0;
        return curr;
}

int largestBst(Node *root)
{
	info i=solve(root);
	return i.ans;
}
