#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
//(x-1,y),(x+1,y),(x,y-1),(x,y+1),(x-1,y-1),(x+
//1,y+1),(x-1,y+1),(x+1,y-1)
int dx[]={-1,1,0,0,-1,1,-1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int vis[n][m];
    int mv=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
            mv=max(mv,a[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==mv) {
                q.push({0,{i,j}});
                vis[i][j]=1;

            }
        }
    }
    int t=0;
    while(!q.empty()){
        auto i =q.front();
        t=q.front().first;
        q.pop();
        int cx=i.second.first;
        int cy=i.second.second;
         for(int i=0;i<8;i++){
            int tx=cx+dx[i];
            int ty=cy+dy[i];
            if(tx>=0 and ty>=0 and tx<n and ty<m and vis[tx][ty]==0){
                q.push({t+1,{tx,ty}});
                vis[tx][ty]=1;
            }
        }
    }
    cout<<t<<endl;
    return;

}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
}
