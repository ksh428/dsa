class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        map<int,vector<int>>m;//which  buses visit this stop
        int n=r.size();
        set<int>busno;
        set<int>stopno;
        for(int i=0;i<n;i++){//i:busno
            for(int j:r[i]){
                m[j].push_back(i);
            }
        }
        //fo every bus stop find the busses that comes here
        //and then for each bus all the not vis stops that is visits is added to queue by
        //increasing 1 level
        queue<int>q;
        q.push(s);
        stopno.insert(s);
        int l=-1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int curr=q.front();
                q.pop();
                if(curr==t) return l+1;
                vector<int>bus=m[curr];
                for(int j:bus){
                    if(busno.find(j)==busno.end()){
                         for(int p:r[j]){
                            if(stopno.find(p)==stopno.end()){
                                stopno.insert(p);
                                q.push(p);
                                busno.insert(j);
                            }
                        }
                    }

                }

            }
            l++;
        }
        return -1;
    }
};
