
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
};

void insert(int n, trieNode* head) {
      trieNode * curr = head;
      for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) { //1
                  if (!curr->right) {
                        curr->right = new trieNode();
                  }
                  curr = curr->right;
            } else { //0
                  if (!curr->left) {
                        curr->left = new trieNode();
                  }
                  curr = curr->left;
            }
      }
}
int findmax(trieNode* head, int val) {
      trieNode* curr = head;
      int currxor = 0;
      for (int j = 31; j >= 0; j--) {
            if (val & (1 << j)) { //1
                  if (curr->left) {
                        currxor += pow(2, j);
                        curr = curr->left;
                  } else curr = curr->right;
            } else { //0
                  if (curr->right) {
                        currxor += pow(2, j);
                        curr = curr->right;
                  } else curr = curr->left;
            }
      }
      return currxor;

}

void solve() {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      trieNode* head = new trieNode();
      int x=a[0];
      int mx=0;
      insert(x,head);
      for(int i=1;i<n;i++){
            x^=a[i];
            mx=max(mx,x);
            int almax=findmax(head,x);
            mx=max(mx,almax);
            insert(x,head);
      }
      cout<<mx<<endl;



}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
