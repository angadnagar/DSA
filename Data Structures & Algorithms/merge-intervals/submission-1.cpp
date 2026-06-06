class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<n;i++){
          int newStart=intervals[i][0];
          int newEnd=intervals[i][1];

          if(newStart>end){
              ans.push_back({start,end});
              start=newStart;
              end=newEnd;
          }

          else if(start <= newEnd){
            start=min(start,newStart);
            end=max(end,newEnd);
          }
        }

        ans.push_back({start,end});

        return ans;
    }
};
