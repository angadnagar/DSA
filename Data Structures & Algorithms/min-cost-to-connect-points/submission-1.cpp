// class DSU{
//     public:
//     vector<int> parent,size;

//     DSU(int n){
//         parent.resize(n+1);
//         size.resize(n+1,1);

//         for(int i=0;i<=n;i++){
//            parent[i]=i;
//         }
//     }

//     int findParent(int node){
//         if(parent[node]!=node){
//             return findParent(parent[node]);
//         }

//         return parent[node];
//     }

//     bool unionSet(int u,int v){
//         int pu = findParent(u);
//         int pv = findParent(v);

//         if(pu==pv)
//         return false;

//         if(size[pu]<size[pv]){
//             swap(pu,pv);
//         }

//         size[pu]+=size[pv];
//         parent[pv]=pu;
//         return true;
//     }
// };

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];

            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];

                int dist = abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }

        int res = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});

        unordered_set<int> vis;

        while(vis.size()<n){
            pair<int,int> curr = pq.top();
            pq.pop();
            int dist = curr.first;
            int node = curr.second;

            if(vis.count(node)){
                continue;
            }

            res+=dist;
            vis.insert(node);

            for(auto &it:adj[node]){
                if(!vis.count(it.second)){
                    pq.push({it.first,it.second});
                }
            }

        }

        return res;
    }
};
