/*
Totient Function
Send Feedback
You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
Input Format:
First line of input will contain T(number of test case), each test case follows as.
An integer N in new line.
Output Format:
For each test case print the answer in new line
Constraints:
1 <= T <= 100
1 <= N <= 10^9
Sample Input:
2
20
21
Sample Output:
8
12
*/

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve(){
      int n;
      cin>>n;
      int s=n;
      for(int i=2;i*i<=n;i++){
            if(n%i==0){
                  while(n%i==0){
                        n/=i;
                  }
                  s-=s/i;
            }
      }
      if(n>1) s-=s/n;
      cout<<s<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  sieve();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
