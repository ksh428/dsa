class Solution{
    public:
    int c=0,d;
        int rightCousin(Node* root,int val){
            if(root->data==val){
                return -1;
            }
            queue<pair<Node*,int>>q;
            q.push({root,c});
            bool found=0;
            while(!q.empty() and !found){
                int l=q.size();
                while(l--){
                    Node* curr=q.front().first;
                    q.pop();
                    if((curr->left and curr->left->data==val) or(curr->right and curr->right->data==val)){
                        d=c+1;
                        c++;
                        found=1;
                    }else{
                        if(curr->left) {
                            c++;
                            q.push({curr->left,c});
                        }
                        if(curr->right){
                            c++;
                            q.push({curr->right,c});
                        }
                    }
                }
            }

            if(found){
                int l=q.size();

                if(l==0) return -1;
                while(!q.empty()){
                    Node* curr=q.front().first;
                    int x=q.front().second;
                    q.pop();
                    if(x>d){
                        return curr->data;
                    }
                }
                if(q.empty()) return -1;

            }else return -1;

        }
};
