#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        //my approach
        /*
        int tot=n*m;
        int ans;
        if(tot&1 && tot!=1){
            if(x>y){
                //select y and 0
                // y sholuld be (tot-tot/2) times
                ans=y*(tot-tot/2);
            }else if(x==y){
                ans=x*(tot/2)+x;
                }
            else if(2x<y){
                ans=x*(tot);
            }else if(2x>=y)
            else{
                //select x and y-x
                int minval=min(x,y-x);
                int maxval=max(x,y-x);
                ans=minval*(tot-tot/2) + maxval*(tot/2);
            }
        }else if(tot==1){
            cout<<x<<endl;
        }

        else{
            if(x>y){
                ans=y*(tot/2);
            }else if(x==y){
                ans=x*(tot/2);
            }

            else{
                ans=x*(tot/2)+(y-x)*(tot/2);
            }
        }
        cout<<ans<<endl;
    }
    */
    int count=n*m;
    int a=count/2;
    int ans=min(2*x,y);

    if(count==1)
    cout<<x<<endl;
    if(count&1){
        if(x>=y){
            cout<<(a+1)*y<<endl;
        }else{
            cout<<a*ans+x<<endl;
        }

    }
    else{
        cout<<a*ans<<endl;
    }
    }

}

