#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

const int N = 1000001;
bool sieve[N + 1];

void create() {
      for(int i=2;i<=N;i++) sieve[i]=1;
	for (int i = 2; i * i <= N; i++) {
		if (sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = 0;
			}
		}
	}
}
vector<int> generateprimes(int n){
      vector<int>v;
      for(int i=2;i<=n;i++){
            if(sieve[i]) v.push_back(i);
      }
      return v;
}

void initcode() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

void solve() {
      int l,r;
      cin>>l>>r;
      vector<int>v=generateprimes(sqrt(r));
      int dummy[r-l+1];
      for(int i=0;i<r-l+1;i++) dummy[i]=1;
      for(auto i:v){
            int firstmutiple=(l/i)*i;
            if(firstmutiple<l) firstmutiple+=i;
            for(int j=max(firstmutiple,i*i);j<=r;j+=i){
                  dummy[j-l]=0;
            }
      }
      for(int i=l;i<=r;i++){
            if(dummy[i-l]){
                  cout<<i<<" ";
            }
      }
      cout<<endl;
}


int32_t main() {
	initcode();
	create();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
