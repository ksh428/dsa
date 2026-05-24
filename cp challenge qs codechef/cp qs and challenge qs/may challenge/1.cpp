
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int diff[n];
	    diff[0]=0;
	   for(int i=1;i<n;i++){
	       diff[i]=a[i]-a[i-1];
	   }
	   int min=100;
	   int max=-1;
	   int c=1;
	   for(int i=1;i<n;i++){
	       if(diff[i]<=2){
	           c++;
	       }else{
	           if(min>c)
	           min=c;
	           if(max<c)
	           max=c;
	           c=1;
	       }
	   }
	   if(min>c)
	   min=c;
	   if(max<c)
	   max=c;
	   cout<<min<<" "<<max<<endl;

	}
}
