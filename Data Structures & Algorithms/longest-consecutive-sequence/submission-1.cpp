class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        int count = 0;
        int maxCount = 0;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }


        for(int i=0;i<n;i++){
            if(!m[nums[i]-1]){
                count=1;
                int val = nums[i];
            while(m[val+1]){
                count++;
                m[val+1]=0;
                val=val+1;

            }

            maxCount=max(maxCount,count);
            count=0;
        
            }
        }

        return maxCount;
    }
};
