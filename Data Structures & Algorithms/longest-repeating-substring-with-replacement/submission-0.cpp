class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;

        unordered_map<char,int> m;

        int maxFreq = 0;

        int ans = 0;

        while(j<n){
           m[s[j]]++;
           maxFreq = max(maxFreq,m[s[j]]);

           while((j-i+1) - maxFreq > k){
            m[s[i]]--;
            i++;
           }

           ans=max(j-i+1,ans);
           j++;
        }

        return ans;
    }
};
