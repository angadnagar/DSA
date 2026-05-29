class Solution {
public:

    int solve(int i,int j,string s,int n,int m,string t,vector<vector<int>>& dp){
        if(j>=m){
            return 1;
        }

        if(i>=n)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans = 0;

        if(s[i]==t[j]){
            ans+=solve(i+1,j+1,s,n,m,t,dp);
        }

        ans+=solve(i+1,j,s,n,m,t,dp);

        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solve(0,0,s,n,m,t,dp);
    }
};
