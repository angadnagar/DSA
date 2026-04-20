class Solution {
public:

    void solve(vector<string>& ans,string& str,int open,int close,int n){
      if(close>open)
      return;
      
      if(open+close==2*n){
        if(open==close){
          ans.push_back(str);
        }
        return;
      }
      
      str+='(';
      solve(ans,str,open+1,close,n);
      str.pop_back();

      str+=')';
      solve(ans,str,open,close+1,n);
      str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string str = "";
        solve(ans,str,0,0,n);

        return ans;
    }
};
