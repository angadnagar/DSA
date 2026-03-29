class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        vector<vector<string>> ans;

        int len = strs.size();

        for(int i=0;i<len;i++){
            string str = strs[i];
            sort(str.begin(),str.end());

            m[str].push_back(strs[i]);
        }

        for(auto &it:m){
           ans.push_back(it.second);
        }

        return ans;
    }
};
