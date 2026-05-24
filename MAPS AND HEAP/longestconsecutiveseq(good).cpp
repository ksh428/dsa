class Solution{
  public:
    int findLongestConseqSubseq(int a[], int n)
    {
      unordered_map<int,bool>m;//value,isstartof sequence
      for(int i=0;i<n;i++) m[a[i]]=1;
      //check for every elemet whether it can be the start of thesequence
      //by checking whether its prev elemet is present in the map or not
      for(int i=0;i<n;i++){
          if(m.find(a[i]-1)!=m.end()) m[a[i]]=0;
      }
      int ans=0;
     for(int i=0;i<n;i++){
         if(m[a[i]]){
             int l=1;
             while(m.find(a[i]+l)!=m.end()) l++;
             ans=max(ans,l);
         }
     }
      return ans;

    }
};
