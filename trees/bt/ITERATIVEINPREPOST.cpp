class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int>inorder;
        vector<int>preorder;
        vector<int>postorder;
        stack<pair<Node*,int>>st;
        st.push({root,1});
        while(!st.empty()){
           if(st.top().second==1){
                 preorder.push_back(st.top().first->data);
               st.top().second++;
               if(st.top().first->left) st.push({st.top().first->left,1});
           }else if(st.top().second==2){
               inorder.push_back(st.top().first->data);
               st.top().second++;
               if(st.top().first->right) st.push({st.top().first->right,1});
           }else {
                postorder.push_back(st.top().first->data);
           }
        }

      //  return ans;
    }
};
