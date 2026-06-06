class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int interval = 0;

        sort(intervals.begin(),intervals.end());

        int prevEnd = intervals[0][1];

        for(int i=1;i<n;i++){

          if(prevEnd <= intervals[i][0]){
            prevEnd=intervals[i][1];
            continue;
          }

           if(prevEnd > intervals[i][0]){
            prevEnd=min(prevEnd,intervals[i][1]);
            interval++;
           }
        }

        return interval;
    }
};
