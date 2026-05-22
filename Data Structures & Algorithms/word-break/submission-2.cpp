class Solution {
public:

    bool solve(string s,int i,unordered_set<string>& st,int n,vector<int>& dp){
        if(i==n){
            return true;
        }

        if(dp[i]!=-1)
        return dp[i]==1;

        for(int j=i;j<n;j++){
            if(st.find(s.substr(i,j-i+1))!=st.end()){
                if(solve(s,j+1,st,n,dp)){
                    dp[i]=1;
                    return true;
                }
            }
        }

        dp[i]=0;

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        vector<int> dp(n,-1);

        unordered_set<string> st(wordDict.begin(),wordDict.end());

        return solve(s,0,st,n,dp);
    }
};
