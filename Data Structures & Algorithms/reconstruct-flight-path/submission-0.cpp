class Solution {
public:

    bool dfs(string src,unordered_map<string,vector<string>>& adj,vector<string>& ans,int target){
      if(ans.size()==target){
        return true;
      }

      if(adj.find(src)==adj.end())
      return false;

      vector<string> temp = adj[src];

      for(int i=0;i<temp.size();i++){
        string str = temp[i];

        adj[src].erase(adj[src].begin()+i);
        ans.push_back(str);
        if(dfs(str,adj,ans,target)){
          return true;
        }
        adj[src].insert(adj[src].begin()+i,str);
        ans.pop_back();

      }

      return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;

        for(auto &it:tickets){
          adj[it[0]];
        }

        sort(tickets.begin(),tickets.end());

        for(auto &it:tickets){
          adj[it[0]].push_back(it[1]);
        }

        vector<string> ans={"JFK"};
        
        dfs("JFK",adj,ans,tickets.size()+1);

        return ans;

    }
};
