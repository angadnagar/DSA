class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
          int n = hand.size();
          if(n%groupSize!=0)
          return false;

          unordered_map<int,int> m;

          for(int i=0;i<n;i++){
            m[hand[i]]++;
          }

          sort(hand.begin(),hand.end());

          for(int i=0;i<n;i++){
            if(m[hand[i]]>0){
              for(int j=hand[i];j<hand[i]+groupSize;j++){
                if(m[j]==0)
                return false;

                m[j]--;
              }
            }
          }

          return true;
    }
};
