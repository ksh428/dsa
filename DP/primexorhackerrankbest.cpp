//https://www.hackerrank.com/challenges/prime-xor/problem

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)




int main(int argc, char const *argv[]) {

	ll max_xor = (1<<13) - 1;
	vector<bool> isPrime(max_xor+5, true);
	isPrime[0] = false;
	isPrime[1] = false;
// 	loop(i, 2, max_xor) {
// 		if(isPrime[i]) {
// 			int j = i * 2;
// 			while(j <= max_xor) {
// 				isPrime[j] = false;
// 				j += i;
// 			}

// 		}
// 	}
    	for(int i=2;i*i<=max_xor;i++){
	    if(isPrime[i]){
	        for(int j=i*i;j<=max_xor;j+=i){
	            isPrime[j]=false;
	        }
	    }
	}
	int q;
	cin>>q;

	while(q--) {
		vector<int> freq(4505, 0);
		int n;
		cin>>n;
		vector<vector<ll> >dp(2, vector<ll> (max_xor+5, 0));
		loop(i, 0, n-1) {
			int x;
			cin>>x;
			freq[x]++;
		}
		dp[0][0] = 1;
		int flag = 1;
		loop(i, 3500, 4500) {
			loop(j, 0, max_xor) {
				if(freq[i] == 0) {
					dp[flag][j] = dp[1-flag][j];
				} else {
					dp[flag][j] = (dp[1-flag][j]*(freq[i]/2 + 1)%mod + dp[1-flag][j^i]*((freq[i]+1)/2)%mod)%mod;
				}
			}
			flag = 1-flag;
		}
		ll ans = 0;
		loop(j, 0, max_xor) {
			if(isPrime[j]) {
				ans = (ans + dp[1-flag][j])%mod;
			}
		}
		cout<<ans<<endl;
	}

}
