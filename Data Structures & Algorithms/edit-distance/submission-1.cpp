class Solution {
public:

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int j=0;j<n2;j++){
          dp[n1][j]=n2-j;
        }

        for(int i=0;i<n1;i++){
          dp[i][n2]=n1-i;
        }

        for(int i=n1-1;i>=0;i--){
          for(int j=n2-1;j>=0;j--){
            if(word1[i]==word2[j]){
              dp[i][j]=dp[i+1][j+1];
            }

            else
            dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
          }
        }

        return dp[0][0];
    }
};
