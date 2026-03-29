class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        stack<int> st;

        int ans = 0;

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<=height[i]){
                int mid = height[st.top()];
                st.pop();

                if(!st.empty()){
                   int right = height[i];
                   int left = height[st.top()];
                   int h = min(left,right)-mid;
                   ans+=h*(i-st.top()-1);
                }
            }

            st.push(i);
        }

        return ans;
    }
};
