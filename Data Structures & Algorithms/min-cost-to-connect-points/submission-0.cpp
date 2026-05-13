class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
           parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]!=node){
            return findParent(parent[node]);
        }

        return parent[node];
    }

    bool unionSet(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv)
        return false;

        if(size[pu]<size[pv]){
            swap(pu,pv);
        }

        size[pu]+=size[pv];
        parent[pv]=pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }

        sort(edges.begin(),edges.end());
        int res = 0;

        for(auto& it : edges){
            if(dsu.unionSet(it[1],it[2])){
                res+=it[0];
            }
        }

        return res;
    }
};
