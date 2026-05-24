#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
void solve(){

}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
        cin>>n;
        int maxi=-1;
        vector<ll>a(100005,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
            maxi=max(maxi,x);
        }
        //f(i)=max(f[i-1],freq[i]*a[i]+f[i-2]);//all numbers till i
        vector<ll>b(100005,0);
        b[0]=0;
        b[1]=a[1];
        for(ll i=2;i<=100000;i++){
            b[i]=max(b[i-1],b[i-2]+(a[i]*i));
        }
        cout<<b[maxi];



}
