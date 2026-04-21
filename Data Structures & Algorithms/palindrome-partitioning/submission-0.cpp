class Solution {
public:

   bool isPalindrome(string& s,int i,int j){
      
      while(i<=j){
        if(s[i]!=s[j])
        return false;

        i++;
        j--;
      }

      return true;
   }

    void solve(string& s,int i,vector<string>& temp,vector<vector<string>>& ans){
      if(i>=s.length()){
        ans.push_back(temp);
        return;
      }

      for(int j=i;j<s.length();j++){
        if(isPalindrome(s,i,j)){
          temp.push_back(s.substr(i,j-i+1));
          solve(s,j+1,temp,ans);
          temp.pop_back();
        }
      }

      
    }
    vector<vector<string>> partition(string s) {
      vector<string> temp;
      vector<vector<string>> ans;
        solve(s,0,temp,ans);

        return ans;
    }
};
