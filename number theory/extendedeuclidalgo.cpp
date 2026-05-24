#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;


class Triplet{
      public:
      int x;
      int y;
      int gcd;
};
//EXTENDED EUCLID EQN:  ax+by=gcd(a,b)
Triplet extendedeuclid(int a,int b){
      if(b==0){ ///if(b==0) ax=a;
            Triplet ans;
            ans.gcd=a;
            ans.x=1;
            ans.y=0;
            return ans;
      }
      Triplet smallans=extendedeuclid(b,a%b);
      Triplet ans;
      ans.gcd=smallans.gcd;
      ans.x=smallans.y;
      ans.y=smallans.x-(a/b)*smallans.y;
      return ans;
}


int32_t main(){
      int a=16;
      int b=10;
      //16x+10y=2
      Triplet ans=extendedeuclid(a,b);
      cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
}
