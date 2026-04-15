class Solution {
public:

    double calculateDist(int x2,int y2){
      return sqrt((x2*x2) + (y2*y2)); 
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;

        vector<vector<int>> ans;

        int n = points.size();

        for(int i=0;i<n;i++){
           double val = calculateDist(points[i][0],points[i][1]);

           pq.push({val,points[i]});

           if(pq.size()>k){
            pq.pop();
           }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
