class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1>n2){
          return findMedianSortedArrays(nums2,nums1);
        }

        int l = 0;
        int r = n1;
        int total = n1+n2;
        int half = (total+1)/2;

        while(l<=r){
          int i = l+(r-l)/2;
          int j = half-i;

          int ALeft = i>0 ? nums1[i-1] : INT_MIN;
          int ARight = i<n1 ? nums1[i] : INT_MAX;
          int BLeft = j>0 ? nums2[j-1] : INT_MIN;
          int BRight = j<n2 ? nums2[j] :INT_MAX;

          if(ALeft<=BRight && BLeft<=ARight){
            if(total%2 == 0){
              return (max(ALeft,BLeft)+min(ARight,BRight))/2.0;
            }

            return max(ALeft,BLeft);
          }

          else if(ALeft>BRight){
            r=i-1;
          }

          else{
            l=i+1;
          }

        }

        return -1;
    }
};
