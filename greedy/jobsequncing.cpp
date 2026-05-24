class Solution
{
    public:
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job a[], int n)
    {
        sort(a,a+n,comp);
        int c=0,prof=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=a[i].dead-1;j>=0;j--){
                if(!vis[j]){
                    c++;
                    prof+=a[i].profit;
                    vis[j]=1;

                    break;
                }
            }
        }
        return {c,prof};

    }
};
