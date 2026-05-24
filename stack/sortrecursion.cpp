

#include <bits/stdc++.h>

using namespace std;


void add(stack<int>&st,int curr){
    if(st.empty() or curr>st.top())
    {
        st.push(curr);
        return;
    }
    int topele=st.top();
    st.pop();
    add(st,curr);
    st.push(topele);
}

void sort(stack<int>&st){
    if(st.empty()) return;
    int curr=st.top();
    st.pop();
    sort(st);
    add(st,curr);
}
//TC:O(N^2)

int main()
{

}

