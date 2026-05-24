#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size();
	    int a[n]={0};
	    int paircount=0;
	    for(int i=0;i<n-1;i++){
	        if(s[i]=='x' && a[i]==0){
	            if(s[i+1]=='y'){
	                paircount++;
	                a[i]=1;
	                a[i+1]=1;
	            }
	        }else if(s[i]=='y' && a[i]==0){
	            if(s[i+1]=='x'){
	                paircount++;
	                a[i]=1;
	                a[i+1]=1;
	            }
	        }
	    }
	    cout<<paircount<<endl;
	}
}

