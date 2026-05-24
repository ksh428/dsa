class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int a[], int l, int h)
    {
        if(l>=h) return;
        int p=partition(a,l,h);
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }

    public:
    int partition (int a[], int l, int h)
    {
        int pivot=a[h];
       int pi=l;
       for(int i=l;i<h;i++){
           if(a[i]<=pivot){
               swap(a[i],a[pi++]);
           }
       }
       swap(a[pi],a[h]);
       return pi;
    }
};
