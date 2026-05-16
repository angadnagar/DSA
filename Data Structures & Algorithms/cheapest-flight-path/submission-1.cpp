class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        unordered_map<int,vector<vector<int>>> adj;

        for(auto &it: flights){
            int i = it[0];
            int j = it[1];
            int d = it[2];

            adj[i].push_back({j,d});
        }

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{src,0}});

        while(!pq.empty()){
          auto curr = pq.top();
          pq.pop();
          int stops = curr.first;
          int node = curr.second.first;
          int d = curr.second.second;

          for(auto &n: adj[node]){
    
            if(n[0] == dst && stops <= k){
                dist[dst]=min(dist[dst],d+n[1]);
            }

            if(n[0] != dst && dist[n[0]]>d+n[1]){
                dist[n[0]]=d+n[1];
                pq.push({stops+1,{n[0],dist[n[0]]}});
            }
          }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];

    }
};
