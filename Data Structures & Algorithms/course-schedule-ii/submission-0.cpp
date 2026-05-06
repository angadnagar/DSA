class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<int> ans;

        vector<vector<int>> adj(numCourses);

        for(auto &it:prerequisites){
            inDegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        int finish = 0;

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
           int course = q.front();
           q.pop();
           finish++;
           ans.push_back(course);

           for(auto &i:adj[course]){
            inDegree[i]--;
            if(inDegree[i]==0){
                q.push(i);
            }
           }
        }

        if(finish != numCourses)
        return {};

        return ans;
    }
};
