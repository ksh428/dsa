/*
Consider an array of size n with all initial values as 0. Perform given ‘m’ add operations
from index ‘a’ to ‘b’ and evaluate highest element in array. An add operation adds 100
to all elements from a to b (both inclusive).
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int pref[n+1]={0};
    int a,b,m;
    cin>>m;
    for(int i=0;i<m;i++){
    cin>>a>>b;
    pref[a]+=100;
    pref[b+1]-=100;

    }
    int mx;
    for(int i=0;i<=n;i++){
    pref[i]+=pref[i-1];
    mx=max(mx,pref[i]);
    }
    cout<<mx;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int pre[5 + 1] = { 0 };
    // 5+1 bc range can end at last index
    int m = 3, mx = 0;
    for (int i = 0; i < m; i++) {
        // take input a and b
        int a, b; // 2 4
        cin >> a >> b; // 1 3
        // 1 2
        // add 100 at first index and -100
        // at last+1 index
        pre[a] += 100;
        pre[b + 1] += -100;
    }
    for (int i = 1; i <= 5; i++) {
        // add all values in a cumulative way
        pre[i] += pre[i - 1];

        // keep track of max value
        mx = max(mx, pre[i]);
    }
    cout << mx;
    return 0;
}
