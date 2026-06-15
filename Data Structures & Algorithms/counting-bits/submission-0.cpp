class Solution {
public:

    int noOfBits(int n){
        int ans = 0;

        while(n>0){
            if(n&1){
                ans+=1;
            }

            n>>=1;
        }

        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i=0;i<=n;i++){
            ans[i]=noOfBits(i);
        }

        return ans;
    }
};
