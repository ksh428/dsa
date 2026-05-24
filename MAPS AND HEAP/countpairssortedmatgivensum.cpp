
int countPairs(int a[][SIZE],int b[][SIZE],int n,int x){
    int c=0;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            st.insert(a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int  ele=x-b[i][j];
            if(st.find(ele)!=st.end()) c++;
        }
    }
    return c;
}

//other approach
int countPairs1(int a[][SIZE],int b[][SIZE],int n,int x){
    int c=0;
    int r1=0,c1=0;
    int r2=n-1,c2=n-1;
    while(r1<n and r2>=0){
        int val=a[r1][c1]+b[r2][c2];
        if(val==x){
            cout<<a[r1][c1]<<" "<<b[r2][c2]<<endl;
            c++;
            c1++;
            c2--;
        }else if(val>x){
            c2--;
        }else{
            c1++;
        }
        if(c1==n){
            c1=0;
            r1++;
        }
        if(c2==-1){
           c2=n-1;
           r2--;
        }
    }


    return c;
}
//sc:1
