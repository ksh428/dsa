
//2 cases
class Solution {
public:
    void pp(Node* root,Node* &first,Node* &mid,Node* &last,Node* &pre){
        if(!root) return ;
        pp(root->left,first,mid,last,pre);
        if(pre and (pre->data)>root->data){
            if(!first){
                first=pre;
                mid=root;
            }else{
                last=root;
            }
        }
        pre=root;
        pp(root->right,first,mid,last,pre);
    }
    void correctBST( struct Node* root )
    {
        Node* pre=NULL;
        Node* mid=NULL;
        Node* last=NULL;
        Node* first=NULL;
        pp(root,first,mid,last,pre);
        if(first and last){
            swap(first->data,last->data);
        }else if(first and mid) swap(first->data,mid->data);
    }
};

