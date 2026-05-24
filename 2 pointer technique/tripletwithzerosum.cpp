//https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1#
bool pairtarget(int a[],int start,int x,int n){
    int j=start,k=n-1;
    while(j<k){
        if(a[j]+a[k]>x) k--;
        else if(a[j]+a[k]<x) j++;
        else return true;
    }
    return false;


}
bool findTriplets(int a[], int n)
{
    //Your code here
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        int ele=a[i];
        if(pairtarget(a,i+1,-ele,n)) return true;
    }
    return false;
}
