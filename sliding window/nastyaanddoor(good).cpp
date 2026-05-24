#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    vector<bool>peak(n,0);
	    for(int i=1;i<n-1;i++){
	        if(a[i]>a[i-1] && a[i]>a[i+1]) peak[i]=1;
	    }
	    int maxlen=0;
	    for(int i=1;i<k-1;i++) if(peak[i]) maxlen++; //check how many peaks are there in the first window of size k(0 to k-1)
	    // since the first and last element cant be peak so dont check thwm

	    int left=1,right=k-1;//for next window // keep right k-1 even for the new window as this element may be a peak for prev window so this can be include in new window
	    //
	    int len=maxlen;
	    int leftptr=1;
	    for(int i=1;i<=(n-k);i++){
	        if(peak[left]) len--; //
	        if(peak[right]) len++;
	        left++;right++;
	        if(len>maxlen){
	            maxlen=len;
	            leftptr=i+1;// 1 based indexing
	        }
	    }
	    cout<<maxlen+1<<" "<<leftptr<<endl;


	}
}
