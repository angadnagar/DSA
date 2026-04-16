class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> m;
        queue<pair<int,int>> q;

        int time = 0;

        for(auto &it:tasks){
            m[it]++;
        }

        for(auto &it:m){
            pq.push(it.second);
        }

        while(!pq.empty()){
            int task = pq.top();
            pq.pop();
            time++;
            
            if(task-1 > 0)
            q.push({task-1,time+n});

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }

            if(pq.empty() && !q.empty()){
                pq.push(q.front().first);
                time=q.front().second;
                q.pop();

            }


        }

        return time;




    }
};
