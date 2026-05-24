//priority_queue is same as max heap in stl (default)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        int f,s;
        while(n>1){
            f=pq.top();
            pq.pop();
            s=pq.top();
            pq.pop();
            n-=2;
            if(f-s>0){
                pq.push(f-s);
                n++;
            }
        }
        if(!pq.empty()) return pq.top();
        else return 0;

    }
};
