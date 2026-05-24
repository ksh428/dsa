

#include <bits/stdc++.h>

using namespace std;

void insertatbottom(stack<int>&st,int curr){
    if(st.empty()){
        st.push(curr);
        return;
    }
    int topele=st.top();
    st.pop();
    insertatbottom(st);
    st.insert(topele);
}

void reverse(stack<int>&st){
    if(st.empty()) return;
    int curr=st.top();
    st.pop();
    reverse(st);
    insertatbottom(st,curr);

}
//TC:O(N^2)

int main()
{

}

