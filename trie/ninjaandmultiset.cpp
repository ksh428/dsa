#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class trieNode {
public:
      trieNode* left;
      trieNode* right;
      int val=0;
};

void insertnode(int n, trieNode* head) {
      trieNode * curr = head;
      for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) { //1
                  if (!curr->right) {
                        curr->right = new trieNode();
                  }

                  curr = curr->right;
                  curr->val+=1;
            } else { //0
                  if (!curr->left) {
                        curr->left = new trieNode();
                  }
                  curr = curr->left;
                  curr->val+=1;
            }
      }
}
void deletenode(int n,trieNode* head){
      trieNode* curr=head;
      for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) { //1
                  // if (!curr->right) {
                  //       curr->right = new trieNode();
                  // }

                  curr = curr->right;
                  curr->val-=1;
            } else { //0
                  // if (!curr->left) {
                  //       curr->left = new trieNode();
                  // }
                  curr = curr->left;
                  curr->val-=1;
            }
      }

}
int findmaxxorpair(trieNode* head, int n) {
      int val =n;
      trieNode* curr = head;
      int currxor = 0;
      for (int j = 31; j >= 0; j--) {
            if (val & (1 << j)) { //1
                  if (curr->left and curr->left->val>0) {
                         currxor += pow(2, j);
                        curr = curr->left;
                  } else curr = curr->right;
            } else { //0
                  if (curr->right and curr->right->val>0) {
                        currxor += pow(2, j);
                        curr = curr->right;
                  } else curr = curr->left;
            }
      }
      return currxor;

}

void solve() {
      trieNode* root=new trieNode();
      int q;
      insertnode(0,root);
      cin>>q;
      while(q--){
            char op;
            int x;
            cin>>op>>x;
            if(op=='+'){
                insertnode(x,root);
            }else if(op=='-'){
                  deletenode(x,root);
            }else{
                  cout<<findmaxxorpair(root,x)<<endl;
            }
      }


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
