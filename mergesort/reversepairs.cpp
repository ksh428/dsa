/*
MERGE SORT GENERAL TEMPLATE
//BUT U SHOUDLD BE FLEXIBLE TO USE TO USE THE NROMAL MERGE SORT TEMPLATE ALSO
int marge(){
    //initialze variables

    //calculate ans : for each i from l to m no of valid j and continue find ans(do not do merging)


    //bring back variables to original pos for mergind

    //merge the 2 arrays


    //copy to original array
    //retrun ans

}
 int mergesort(vector<int>&a,int l,int r){
        int ans=0;
        if(l<r){
            int m=(l+r)/2;
            ans+=mergesort(a,l,m);
            ans+=mergesort(a,m+1,r);
            ans+=merge(a,l,m,r);
        }
        return ans;
    }
    int reversePairs(vector<int>& a) {
        int n=a.size();
        return mergesort(a,0,n-1);
    }


*/





class Solution {
public:
#define ll long long
    int merge(vector<int>&a,int l,int m,int r){
        int c=0;
        int j=m+1;
        //calculate
        //for every i how many j are there
        //so for every subsequent i all those j who satisfied for prev i will also be there
        for(int i=l;i<=m;i++){
            while(j<=r and a[i]>2*1ll*a[j]) j++;
            c+=(j-m-1);
        }
        int temp[r-l+1];
        int i=l;
        j=m+1;
        int k=0;
        while(i<=m and j<=r){
            if(a[i]<=a[j]){
                temp[k++]=a[i++];
            }else temp[k++]=a[j++];
        }
        while(i<=m) temp[k++]=a[i++];
        while(j<=r) temp[k++]=a[j++];
        k=0;
        for(int i=l;i<=r;i++) a[i]=temp[k++];
        return c;

    }
    int mergesort(vector<int>&a,int l,int r){
        int ans=0;
        if(l<r){
            int m=(l+r)/2;
            ans+=mergesort(a,l,m);
            ans+=mergesort(a,m+1,r);
            ans+=merge(a,l,m,r);
        }
        return ans;
    }
    int reversePairs(vector<int>& a) {
        int n=a.size();
        return mergesort(a,0,n-1);
    }
};
