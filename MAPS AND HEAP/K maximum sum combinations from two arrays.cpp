void solve() {
      sort(a.rbegin(),a.rend());
      sort(b.rbegin(),b.rend());
      set<pair<int,int>>st;
      priority_queue<pair<int,pair<int,int>>>pq;
      pq.push({a[0]+b[0],0,0});
      st.insert({0,0});
      while(k){
            cout<<pq.top()<<" ";
            auto curr=pq.top();
            pq.pop();
            int ai=curr.second.first;
            int bi=curr.second.second;
            if(st.find({ai+1,bi})==st.end()){
                  st.insert({ai+1,bi});
                  pq.push({a[ai+1]+b[bi],b[bi],{ai+1,bi}});
            }
            if(st.find({ai,bi+1})==st.end()){
                  st.insert({ai,bi+1});
                  pq.push({a[ai]+b[bi+1],b[bi+1],{ai,bi+1}});
            }
            k--;
      }
}
