#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int k;
	    cin>>k;
	    queue<int>q;
	    int i;
	    for(i=0;i<k;i++){
	        if(a[i]<0) q.push(i);
	    }
	    for(;i<n;i++){
	        if(!q.empty()) cout<<a[q.front()]<<" ";
	        else cout<<"0"<<" ";
	        if(!q.empty() && q.front()<i-k+1) q.pop();
	        if(a[i]<0) q.push(i);
	    }
	    if(!q.empty()) cout<<a[q.front()]<<" ";
	    else cout<<"0"<<" ";
	    cout<<endl;
	}
	return 0;
}
