class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        vector<pair<int,int>> q;

        for(int i=0;i<m;i++){
           q.push_back({queries[i],i});
        }

        sort(q.begin(),q.end());

        sort(intervals.begin(),intervals.end());
  

        vector<int> ans(m,-1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int i=0;

        for(auto &[query,index]:q){
           while(i<n && intervals[i][0]<=query){
            pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
            i++;
           }

           while(!pq.empty() && pq.top().second < query){
            pq.pop();
           }

           if(!pq.empty()){
            ans[index]=pq.top().first;
           }


        }

       

        return ans;

        
    }
};
