class Solution {
public:

    bool solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>& dp){
        if(k>=s3.size()){
            return i>=s1.size() && j>=s2.size();
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        bool ans = false;

        if(s3[k]==s1[i] && i<s1.size()){
            ans = solve(i+1,j,i+1+j,s1,s2,s3,dp);
        }

        if(s3[k]==s2[j] && j<s2.size()){
            ans = solve(i,j+1,i+j+1,s1,s2,s3,dp);
        }

        dp[i][j]=ans;

        return ans;

        
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if(n1+n2 != n3)
        return false;


        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
