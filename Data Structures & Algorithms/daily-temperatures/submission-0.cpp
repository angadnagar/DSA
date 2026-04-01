class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);

        stack<int> st;

        for(int i=0;i<n;i++){
            if(!st.empty()){
                while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                    int index = st.top();
                    st.pop();
                    ans[index]=i-index;
                }
                st.push(i);
            }

            st.push(i);
        }

        return ans;
    }
};
