#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int B,C;
bool possible(int s){
    int i=0,j=0;
    while(i<B && j<C){
        //check if clans is reached
        if(dishes[i].first<clans[j].first){
            //not reached
            s-=dishes[i].second;
            if(s<=0)
                return false;
            b++;
        }else {//reached
            if(s>clans[j].second.first){
                s+=clans[j].second.second;
            }
            j++;
        }
    }
    while(i<B){
        s-=dishes[i].second;
        i++;
        is(s<=0) return false;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //INPUT
        int X;
        cin>>X;
        cin>>B;
        vector<pair<int,ll > > dishes;
        vector<pair<int,pair<ll,ll > > >clans;
        int xi,pi;
        ll yi,qi,ri;
        for(int i=0;i<B;i++){
            cin>>xi>>yi;
            dishes.push_back(make_pair(xi,yi));
        }
        cin>>C;
        for(int i=0;i<C;i++){
            cin>>pi>>qi>>ri;
            clans.push_back(make_pair(pi,(make_pair(qi,ri))));
        }
        //INPUT END
        //NOW perform bs
        ll left=0,right=1;
        for(int i=0;i<B;i++){ //total no. of men needed when there is no clan.
                //this is the max numbner of total men needed as when there are clan the number of men
                //needed will be smaller as the clan population may be included
            right+=dishes[i].second;
        }

        while(left<right){
            ll mid=(left+right)/2;
            if(possible(mid)){
                //try for lesser no of people
                right=mid;
            }else left=mid+1;
        }
        //doubt..
        if(possible[right])
            return right;
        else return right+1;

    }
}
