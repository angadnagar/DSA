/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
       int n = intervals.size();

       vector<int> start,end;

       for(auto& i:intervals){
        start.push_back(i.start);
        end.push_back(i.end);
       }

       sort(start.begin(),start.end());
       sort(end.begin(),end.end());

       int count = 0;
       int ans = 0;

       int s=0;
       int e=0;

       while(s<n){
        if(start[s]<end[e]){
          count++;
          s++;
        }

        else{
          count--;
          e++;
        }

        ans=max(ans,count);
       }

       return ans;
    }
};
