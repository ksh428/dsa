class Solution{
    public:
    #define range 255
    //Function to arrange all letters of a string in lexicographical
    //order using Counting Sort.
    string countSort(string s){
        // code here
        int n=s.size();
        char ans[n];
        int count[range+1];
        memset(count,0,sizeof(count));
        for(char c:s) count[c]++;
        //conv to prefix
        for(int i=1;i<=range;i++){
            count[i]+=count[i-1];
        }
        for(char c:s){
            ans[count[c]-1]=c;
            count[c]--;
        }
        string res="";
        for(char c:ans) res+=c;
        return res;
    }
};
//handling negative nos

 int a[]={-3,2,-3,5};
   int n= sizeof(a)/sizeof(a[0]);
   int mx=0,mn=1000;
   for(int x:a) mx=max(mx,x),mn=min(mn,x);
   int range=mx-mn+1;
   vector<int>count(range,0);
   for(int x:a) count[x-mn]++;
   for(int i=1;i<=range;i++) count[i]+=count[i-1];
   int ans[n];
   for(int x:a){
       ans[count[x-mn]-1]=x;
       count[x-mn]--;
   }
   for(int x:ans) cout<<x<<" ";
