#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,x1,x2,x3;
        cin>>a>>b;
        cin>>x1>>x2>>x3;
        /*
        if(x1>=a && x2>=b){

            cout<<"YES"<<endl;

        }else if(x1<=a && x2>=b){

            int minx3=a-x1;
            if(minx3<=x3)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }else if(x1>=a && x2<=b){

            int minx3=b-x2;
            if(minx3<=x3)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

        }else{

            int val1=a-x1;
            int val2=b-x2;
            int minx3=max(val1,val2);
            if(minx3<=x3)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
                */
            int mini=min(a,b);
            int placed=min(mini,x3);
            a-=placed;
            b-=placed;
            if(a<=x1 && b<=x2)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;


        }
}
}
