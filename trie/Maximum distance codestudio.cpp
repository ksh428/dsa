
#include<bits/stdc++.h>
struct Node{
    Node* links[2];
    int f=0;
};
int ans=0;
void insert(Node* root,string s){
    Node* node=root;
    for(char c:s){
        if(node->links[c-'0']==NULL){
            node->links[c-'0']=new Node();
        }
        node=node->links[c-'0'];
    }
    node->f=1;
}
int dfs(Node* root){
    if(!root) return 0;
    return max(dfs(root->links[0]),dfs(root->links[1]))+1;
}
void query(Node* root){
    Node* node=root;
    queue<Node*>q;
    q.push(node);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->links[0]!=NULL and curr->links[1]!=NULL){
            ans=max(ans,dfs(curr->links[0])+dfs(curr->links[1]));
            q.push(curr->links[0]);
            q.push(curr->links[1]);
        }else{
            if(curr->links[0]) q.push(curr->links[0]);
            else if(curr->links[1]) q.push(curr->links[1]);
        }
    }
}
int maximumDistance(vector<string> &a)
{
    ans=0;
    int n=a.size();
    Node* root=new Node();
    for(auto it:a){
        insert(root,it);
    }
    query(root);
    return ans;
}
