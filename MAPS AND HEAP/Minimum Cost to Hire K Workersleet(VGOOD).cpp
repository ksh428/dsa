
class Solution {
public:
    //exp in notes
    //capration>workerration
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n=q.size();
        double ans =INT_MAX;
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            double x=(double)w[i]/(double)q[i];
            v.push_back({x,q[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;//max quality
        double s=0;
        for(int i=0;i<k;i++){
            s+=v[i].second;
            pq.push(v[i].second);
        }
        ans=min(ans,v[k-1].first*s);

        for(int i=k;i<n;i++){//i:captiain
           double capx=v[i].first;
           s-=pq.top();
            pq.pop();
            pq.push(v[i].second);
            s+=v[i].second;
            ans=min(ans,capx*s);
        }
        return ans;

    }
};
/*
1.ratio of quality=ratio of wage between any 2 workers. and for atleast 1 i (captain)we will give it wage acc to its min req or else we will end up giving more money to all which is unnec.
So for every i assume i to be the captain and calc captain ration=w/q and accto that find the wage of all other elements and take the k smallest , the final ans is min of all-->>TLE
2. we notice that capratio*q[i]>=w[i] for all i, so capratio>=workratio[i]
so we can sort the array acc to the ratio and start assuming to be captain from i=k-1--->TLE
3.for a captain i I need min k-1 values of q[j] and we can multiply it with capratio to get the ans for this captain, so we can maintain a pq (max which will contain max value of q[j] j<i)
and whenever we start iterating from i=k to n-1 for captain i just remove the highest q[j](since we need only k elements) from sum and pq and the current q for the captain to s and pq*/
