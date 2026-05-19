class Solution {
public:

    // int solve(string s,int i,int n,vector<int>& dp){
    //    if(i==n){
    //     return 1;
    //    }

    //    if(s[i]=='0')
    //    return 0;

    //    if(dp[i]!=-1)
    //    return dp[i];

    //    int res = solve(s,i+1,n,dp);

    //    if(i+1 < n){
    //     if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
    //       res+=solve(s,i+2,n,dp);
    //     }
    //    }

    //    return dp[i]=res;
    // }

    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n+1,0);

        dp[n]=1;

        // return solve(s,0,n,dp);

        for(int i=n-1;i>=0;i--){
          if(s[i]!='0'){
            dp[i]=dp[i+1];
          }

          if(i+1 < n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            dp[i]+=dp[i+2];
          }
        }

        return dp[0];
    }
};
