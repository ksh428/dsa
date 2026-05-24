
int maxLen(int a[], int n)
{
    unordered_map<int,int>m;
    m[0]=-1;
    int maxlen=0;
    int i=-1;
    int s=0;
    while(i<n-1){
        i++;
        s+=a[i];
        if(m.find(s)!=m.end()){
            int len=i-m[s];
            if(len>maxlen) maxlen=len;
        }else m[s]=i;
    }
    return maxlen;

}
