class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n+1);

        vector<int> vis(n+1,0);
        vector<int> inDegree(n+1,0);

        queue<int> q;

        for(auto &it:edges){
          adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
          inDegree[it[0]]++;
          inDegree[it[1]]++;

        }

        for(int i=1;i<=n;i++){
          if(inDegree[i]==1){
             q.push(i);
          }
        }

        while(!q.empty()){
          int node = q.front();
          vis[node]=1;
          inDegree[node]--;
          q.pop();

          for(auto &it:adj[node]){
            if(!vis[it]){
               inDegree[it]--;
               if(inDegree[it]==1){
                q.push(it);
               }
            }
          }
        }

        for(int i=n-1;i>=0;i--){
          if(inDegree[edges[i][0]]>1 && inDegree[edges[i][1]]>1){
            return {edges[i][0],edges[i][1]};
          }
        }

        return {};

    }
};
