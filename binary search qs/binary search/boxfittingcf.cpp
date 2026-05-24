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
	    int n,w;
	    cin>>n>>w;
	    multiset<int>ms;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        ms.insert(x);
	    }
	    int h=1;
	    int temp=w;
	    while(!ms.empty()){
	        auto it=ms.upper_bound(temp);//first element greater than left space
	        if(it==ms.begin()){//if the smallest box is greater than left space
	            //no suitbale element
	            h++;
	            temp=w;
	        }else{
	            it--; //largest element<=left space
	            temp-=*it;
	            ms.erase(it);
	        }
	    }
	    cout<<h<<endl;
	}
}
