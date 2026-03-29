class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_map<char,int> m;
        
        int count = 0;
        int maxCount = 0;

        while(j<n){
            m[s[j]]++;

            count++;

            while(m[s[j]]>1){
                m[s[i]]--;
                count--;
                i++;
            }

            maxCount=max(count,maxCount);

            j++;

        }

        return maxCount;
    }
};
