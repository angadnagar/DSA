class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);

        dist[k]=0;

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &it:times){
          int u = it[0];
          int v = it[1];
          int w = it[2];

          adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
          int node = pq.top().second;
          int d = pq.top().first;

          pq.pop();

          for(auto &it:adj[node]){
            int t = it.second;
            int nei = it.first;
            if(d+t < dist[nei]){
              dist[nei]=d+t;
              pq.push({dist[nei],nei});
            }
          }
        }

        int maxi = *max_element(dist.begin()+1,dist.end());

        return maxi==INT_MAX ? -1 : maxi;
    }
};
