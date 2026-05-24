
class Solution {
public:
   struct Node{
    Node* left;
    Node* right;
    int c=0;
  };
    void insert(Node* head,int n){
        Node* node=head;
        for(int i=14;i>=0;i--){
            if(n&(1<<i)){
                if(!node->right){
                    node->right=new Node();
                }
                node=node->right;
                node->c+=1;
            }else{
                if(!node->left){
                    node->left=new Node();
                }
                node=node->left;
                node->c+=1;
            }
        }
    }
    int getcount(Node* root){
        return (root==NULL)?0:root->c;
    }
    int query(Node* root,int high,int v,int index){
        //its better to solve this recursively
        if(!root) return 0;
        if(index==-1) return getcount(root);
        int bitv=(v&(1<<index))>0?1:0;
        int bith=(high&(1<<index))>0?1:0;
        if(bitv==0){
            if(bith==0){
                return query(root->left,high,v,index-1);
            }else{
                return getcount(root->left)+query(root->right,high,v,index-1);
            }
        }else{
            if(bith==0){
                return query(root->right,high,v,index-1);
            }else{
                return query(root->left,high,v,index-1)+getcount(root->right);
            }

        }
    }
    int countPairs(vector<int>& nums, int low, int high) {
        Node* root=new Node();
        int c=0;
        //first query then insert to avoid duplicasy
        for(int x:nums){
            c+=query(root,high,x,14);
            c-=query(root,low-1,x,14);
            insert(root,x);
        }
        return c;
    }
};
