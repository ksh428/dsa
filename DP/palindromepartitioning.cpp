//memoization


// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    bool ispal(string s,int start,int end){
        int f=0;
        while(start<=end){
            if(s[start]!=s[end]){
                f=1;
                break;
            }
            start++;end--;
        }
        return f==0;
    }

    int dp[1001][1001];

    int solve(string s,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=j or ispal(s,i,j)) return dp[i][j]=0;

        int c=0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int left,right;
            if(dp[i][k]!=-1) left=dp[i][k];
            else left=solve(s,i,k),dp[i][k]=left;

            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            else right=solve(s,k+1,j),dp[k+1][j]=right;

            c=left+1+right;
            ans=min(ans,c);
        }
        return dp[i][j]=ans;

    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int n=str.size();
        return solve(str,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

//BOTTOM UP o(n^3)

// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n=str.size();
        int dp[n][n];
        bool p[n][n];
        memset(dp,0,sizeof(dp));
        memset(p,1,sizeof(dp));
        for(int l=2;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                int j=i+l-1;
                if(l==2) p[i][j]=(str[i]==str[j]);
                else p[i][j]=(str[i]==str[j]) and p[i+1][j-1];
                if(p[i][j]) dp[i][j]=0;
                else {
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+1+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

//bottom up o(n^2)

// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
    int C[n];
    bool P[n][n];

    int i, j, k, L;


    for (i = 0; i < n; i++) {
        P[i][i] = true;
    }

    for (L = 2; L <= n; L++) {
        for (i = 0; i < n - L + 1; i++) {
            j = i + L - 1;
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }

    for (i = 0; i < n; i++) {
        if (P[0][i] == true)
            C[i] = 0;
        else {
            C[i] = INT_MAX;
            for (j = 0; j < i; j++) {
                if (P[j + 1][i] == true && 1 + C[j] < C[i])
                    C[i] = 1 + C[j];
            }
        }
    }
    return C[n - 1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

