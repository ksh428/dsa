struct meetings{
    int start;
    int end;
};

class Solution
{
    public:
   static bool comp(meetings a,meetings b){
        return a.end<b.end;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meetings m[n];
        for(int i=0;i<n;i++){
            m[i].start=start[i];
            m[i].end=end[i];
        }
        sort(m,m+n,comp);
        int c=1;//first always
        int i=0;
        for(int j=1;j<n;j++){
            if(m[j].start>m[i].end) {
                c++;
                i=j;

            }
        }
        return c;


    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
