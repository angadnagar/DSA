class Solution {
public:

    bool solve(int i,int open,string& s,vector<vector<int>>& dp){
      if(i>=s.length()){
        return open==0;
      }

      if(open<0)
      return false;

      if(dp[i][open]!=-1)
      return dp[i][open];

      if(s[i]=='('){
        return dp[i][open]=solve(i+1,open+1,s,dp);
      }

      else if(s[i]==')'){
        return dp[i][open]=solve(i+1,open-1,s,dp);
      }

      else{
        return dp[i][open]=solve(i+1,open,s,dp) || solve(i+1,open+1,s,dp) || solve(i+1,open-1,s,dp);
      }
    }

    bool checkValidString(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(0,0,s,dp);
    }
};