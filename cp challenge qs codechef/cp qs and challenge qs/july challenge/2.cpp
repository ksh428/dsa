//we could have used the general approach of finding the sum of digit also
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){                 //10 4
                                //8 12
    int n;                      //7 6
    cin>>n;
    ll x,y;
    ll pointschef=0;
    ll pointsmorty=0;

    for(int j=0;j<n;j++){

    cin>>x>>y;
    //x chef y morty
    ostringstream str1,str2;
    str1<<x;
    str2<<y;
    string sx=str1.str();
    string sy=str2.str();
    ll sumx=0;
    ll sumy=0;
    //count for chef
    for(int i=0;i<sx.size();i++){
        sumx+=(sx[i]-48);
    }
    //morty
    for(int i=0;i<sy.size();i++){
        sumy+=(sy[i]-48);
    }

    if(sumx>sumy)
    pointschef++;
    else if(sumx==sumy)
    {
        pointsmorty++;
        pointschef++;
    }
    else pointsmorty++;

    }//all round ends

    if(pointschef>pointsmorty){
        cout<<"0"<<" "<<pointschef<<endl;
    }else if(pointsmorty>pointschef){
        cout<<"1"<<" "<<pointsmorty<<endl;
    }else{
        cout<<"2"<<" "<<pointschef<<endl;
    }
    }
}
