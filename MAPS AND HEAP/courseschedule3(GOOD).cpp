
class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    //keep taking the courses in the sorted order
    //whenever its endging time exceeds just remove the course which takes the
    //highest duration uptile the curr course
    int scheduleCourse(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),comp);
        int ans=0;
        int c=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            c+=a[i][0];
            pq.push(a[i][0]);
            ans++;
            if(c>a[i][1]){
                c-=pq.top();
                ans--;
                pq.pop();
            }
        }
        return ans;
    }
};
