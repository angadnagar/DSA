class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_map<char,int> m;
        
        int maxCount = 0;

        while(j<n){
            m[s[j]]++;

            while(m[s[j]]>1){
                m[s[i]]--;
                i++;
            }

            maxCount=max(j-i+1,maxCount);

            j++;

        }

        return maxCount;
    }
};
