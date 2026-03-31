class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();

        for(int i=0;i<n;i++){
           if(tokens[i]=="+"){
             int val1 = st.top();
             st.pop();
             int val2 = st.top();
             st.pop();

             st.push(val2+val1);
           }
           else if(tokens[i]=="-"){
             int val1 = st.top();
             st.pop();
             int val2 = st.top();
             st.pop();

             st.push(val2-val1);
           }
           else if(tokens[i]=="*"){
             int val1 = st.top();
             st.pop();
             int val2 = st.top();
             st.pop();

             st.push(val2*val1);
           }
           else if(tokens[i]=="/"){
             int val1 = st.top();
             st.pop();
             int val2 = st.top();
             st.pop();

             st.push(val2/val1);
           }
           else{
              st.push(stoi(tokens[i]));
           }
        }

        return st.top();
    }
};
