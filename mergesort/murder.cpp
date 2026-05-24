/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
int merge(int a[],int l,int m,int r){
      int i=l,j=m,k=0;
      int temp[r-l+1];
      int c=0;
      while(i<m and j<=r){
            if(a[i]<a[j]){
                  c+=(a[i]*(r-j+1));
                  temp[k++]=a[i++];
            }else temp[k++]=a[j++];
      }
      while(i<m) temp[k++]=a[i++];
      while(j<=r) temp[k++]=a[j++];
      for(int i=l,k=0;i<=r;k++,i++) a[i]=temp[k];
      return c;
}
int mergesort(int a[],int l,int r){
      int c=0;
      if(l<r){
            int m=(l+r)/2;
            c+=mergesort(a,l,m);
            c+=mergesort(a,m+1,r);
            c+=merge(a,l,m+1,r);
      }
      return c;
}
void solve(){
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++) cin>>a[i];
     int ans=mergesort(a,0,n-1);
     cout<<ans<<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
