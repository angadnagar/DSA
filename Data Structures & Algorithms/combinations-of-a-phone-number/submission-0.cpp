class Solution {
public:
    
    vector<string> digitToCharacters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
       if(!digits.size())
       return ans;

       backtrack(digits,0,"",ans);

       return ans;
    }

    void backtrack(string& digits,int i,string temp,vector<string>& ans){
      if(i==digits.size()){
        ans.push_back(temp);
        return;
      }

      string letters = digitToCharacters[digits[i]-'0'];

      for(char ch:letters){
        backtrack(digits,i+1,temp+ch,ans);
      }
    }
};
