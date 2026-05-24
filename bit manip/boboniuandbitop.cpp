//cf

#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;
vector<int>a(201);
vector<int>b(201);
int n,m;

bool valid(int x){
    //final ans is x;
    for(int i=0;i<n;i++){
        bool flag=0;
        for(int j=0;j<m;j++){
            int t=a[i]&b[j];
            if((t|x)==x){
                flag=true;
                break;
            }
        }
        if(flag==false) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	//use brute force
	//check for all possible values of c from 0 to 2e9
	for(int i=0;i<(1<<9);i++){
	    if(valid(i)){
	        cout<<i;
	        break;
	    }
	}

}
