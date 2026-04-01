class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> posAndSpeed;

        for(int i=0;i<n;i++){
          posAndSpeed.push_back({position[i],speed[i]});
        }

        sort(posAndSpeed.begin(),posAndSpeed.end(),greater<>());

        stack<double> st;

        for(int i=0;i<n;i++){
          double time = (double)(target-posAndSpeed[i].first)/posAndSpeed[i].second;

          if(st.empty())
          st.push(time);

          else if(st.top()<time){
               st.push(time);
          }

        }

        return st.size();

        
    }
};
