
#include<bits/stdc++.h>

void findMedian(int *a, int n)
{
   // ordered_set st;
  //  vector<int>ans;
    priority_queue<int>lower;
    priority_queue<int,vector<int>,greater<int>>higher;
    for(int i=1;i<=n;i++){
        int no=i;
        if(!lower.empty() and a[i-1]<lower.top()){
            lower.push(a[i-1]);
            if(lower.size()>higher.size()+1){
                higher.push(lower.top());
                lower.pop();
            }
        }else{
            higher.push(a[i-1]);
            if(higher.size()>lower.size()+1){
                lower.push(higher.top());
                higher.pop();
            }
        }
        if(no&1){
            if(lower.size()>higher.size()){
                cout<<lower.top()<<" ";
            }else{
                cout<<higher.top()<<" ";
            }
        }else{
            cout<<(lower.top()+higher.top())/2<<" ";
        }

    }
    cout<<endl;

}
