
// C++ Program to implement
// the above appraoach
#include <bits/stdc++.h>
using namespace std;

// Function to count total
// number of valid substrings
int countSub(string s)
{
      int n=s.size();
      unordered_map<char,int>m;
      // int i=0,j=0;
      // int ans=0;
      // while(1){
      //       bool f1=0;
      //       bool f2=0;
      //       while(j<n){
      //             f1=1;
      //             m[s[j]]++;
      //             if(m[s[j]]>1) break;
      //             else ans+=j-i;
      //             j++;
      //       }
      //       while(i<j){
      //             f2=1;
      //             m[s[i]]--;
      //             if(m[s[i]]==1){
      //                   ans+=j-i;
      //                   break;
      //             }
      //             i++;
      //       }
      //       if(f1==0 and f2==0) break;
      // }
      // return ans;
      int ans=0,i=0,j=0;
      while(j<n){
            while(m[s[j]]>1){
                  m[s[i]]--;
                  i++;
            }
            m[s[j]]++;
            ans+=j-i;
            j++;
      }
      return ans;

}

// Driver Code
int main()
{
	string str = "gffg";

	cout << countSub(str);

	return 0;
}
