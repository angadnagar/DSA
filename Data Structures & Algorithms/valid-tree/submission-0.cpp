class Solution {
public:

    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
      vis[node]=1;

      for(auto &it:adj[node]){
         if(!vis[it]){
          if(!dfs(it,node,adj,vis))
          return false;
         }

         else if(it!=parent)
         return false;
      }

      return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
      if(edges.size()!=n-1)
      return false;

      vector<vector<int>> adj(n);

      for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }

      vector<int> vis(n,0);

      if(!dfs(0,-1,adj,vis)){
        return false;
      }

      for(auto &v:vis){
        if(v==0)
        return false;
      }

      return true;
        
    }
};
