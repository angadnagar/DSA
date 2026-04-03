class Solution {
public:

    int calcTime(vector<int>& piles,int n,int mid,int h){
        int time = 0;

        for(int i=0;i<n;i++){
            if(piles[i]<=mid){
                time++;
            }

            else{
                time+=ceil((double)piles[i]/mid);
            }
        }

        return time;


    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi = 0;

        for(int i=0;i<n;i++){
           maxi = max(maxi,piles[i]);
        }

        int i = 1;
        int j = maxi;

        int ans = -1;

        while(i<=j){
            int mid = i+(j-i)/2;

            int time = calcTime(piles,n,mid,h);

            if(time<=h){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        return ans;
    }
};
