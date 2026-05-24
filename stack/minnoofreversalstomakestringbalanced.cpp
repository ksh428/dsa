int countRev (string s)
{
    int n=s.size();
    if(n&1) return -1;
    stack<int>st;
    for(char c:s){
        if(c=='{') st.push(c);
        else{
            if(!st.empty() and st.top()=='{') st.pop();
            else st.push(c);
        }
    }
    int x=0,y=0;
    while(!st.empty()){
        if(st.top()=='{') x++;
        if(st.top()=='}') y++;
        st.pop();
    }
    double x1=(double)x/(double)2;
    double y1=(double)y/(double)2;
    int ans=ceil(x1)+ceil(y1);
    return ans;
}


//BETTER
int countRev (string s)
{
    int n=s.size();
    if(n&1) return -1;
    int op=0,cl=0;
    int ans=0;
    for(char c:s){
        if(c=='{') op++;
        else cl++;
        if(cl>op){
            ans+=(cl-op);
            swap(op,cl);
        }
    }
    ans+=(op-cl)/2;
    return ans;

}
