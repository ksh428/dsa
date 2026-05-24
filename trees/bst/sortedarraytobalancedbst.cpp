class Solution {
public:
    vector<int>res;
    Node* makebst(vector<int>a,int l,int r){
        if(l>r) return NULL;
        int m=(l+r)/2;
        Node* newnode=new Node(a[m]);
        newnode->left=makebst(a,l,m-1);
        newnode->right=makebst(a,m+1,r);
        return newnode;
    }
    vector<int> sortedArrayToBST(vector<int>& a) {
        Node* balbst=makebst(a,0,a.size()-1);
    }
};
