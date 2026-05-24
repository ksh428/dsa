
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void initcode() {
#ifndef ONLINE_JUDGE

      freopen("input.txt", "r", stdin);

      freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

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
int findmaxxorpair(trieNode* head, int a[], int n) {
      int ans = INT_MIN;
      for (int i = 0; i < n; i++) {
            int val = a[i];
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
            ans = max(ans, currxor);
      }
      return ans;

}
void solve() {
      int a[6] = {0, 1, 2, 15, 10, 5};
      trieNode* head = new trieNode();
      for (int i = 0; i < 6; i++) {
            insert(a[i], head);
      }
      cout << findmaxxorpair(head, a, 6);


}


int32_t main() {
      initcode();
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      solve();
      return 0;
}
