class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
          m[s[i]]=i;
        }

        int size=0;
        int end=0;
        vector<int> ans;

        for(int i=0;i<n;i++){
          size++;
          end=max(end,m[s[i]]);

          if(i==end){
            ans.push_back(size);
            size=0;
          }
        }

        return ans;
    }
};
