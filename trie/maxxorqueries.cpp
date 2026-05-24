//offline queries

#include<bits/stdc++.h>
struct Node{
    Node* left;
    Node* right;
};
void insert(int n,Node* head){
    Node* node=head;
    for(int i=31;i>=0;i--){
        if(n&(1<<i)){
            if(!node->right){
                node->right=new Node();
            }
            node=node->right;
        }else{
            if(!node->left){
                node->left=new Node();
            }
            node=node->left;
        }
    }
}
int maxxorpair(int val,Node* head){
   int curr=0;
    Node* node=head;
    for(int j=31;j>=0;j--){
          if(val&(1<<j)){
                if(node->left){
                    curr|=(1<<j);
                    node=node->left;
                }else node=node->right;
            }else{
                if(node->right){
                    curr|=(1<<j);
                    node=node->right;
                }else node=node->left;
            }
    }
    return curr;
}
bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
vector<int> maxXorQueries(vector<int> &a, vector<vector<int>> &q){
	int m=q.size();
    int n=a.size();
    vector<int>ans(m,0);
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        q[i].push_back(i);
    }
    sort(q.begin(),q.end(),comp);
     Node* root=new Node();
    int i=0;
    for(int j=0;j<m;j++){
        while(i<n and a[i]<=q[j][1]){
            insert(a[i],root);
            i++;
        }
       if(i==0){
           ans[q[j][2]]=-1;
       }else ans[q[j][2]]=maxxorpair(q[j][0],root);
    }
    return ans;
}
