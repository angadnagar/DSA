class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);

        for(auto& it:prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        int finish = 0;

        while(!q.empty()){
            int course = q.front();
            q.pop();

            finish++;

            for(auto &i:adj[course]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }

        return finish == numCourses;
    }
};
