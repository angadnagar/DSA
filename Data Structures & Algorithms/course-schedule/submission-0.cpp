class Solution {
public:

    unordered_set<int> visited;

    bool dfs(int i,vector<vector<int>>& adj){

      if(visited.count(i)){
        return false;
      }

      if(adj[i].empty())
      return true;
      
      visited.insert(i);

      for(auto &it:adj[i]){
        if(!dfs(it,adj)){
          return false;
        }
      }

      visited.erase(i);
      adj[i].clear();
      

      return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(auto &pre:prerequisites){
          adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++){
          if(!dfs(i,adj))
          return false;
        }

        return true;
    }
};
