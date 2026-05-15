class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> inDegree;

        int n = words.size();

        for(string s:words){
          for(char ch:s){
            adj[ch]=unordered_set<char>();
            inDegree[ch]=0;
          }
        }

        for(int i=0;i<n-1;i++){
          string word1 = words[i];
          string word2 = words[i+1];

          int minLen = min(word1.length(),word2.length());

          if(word1.length()>word2.length() && word1.substr(0,minLen)==word2.substr(0,minLen)){
            return "";
          }

          for(int j=0;j<minLen;j++){
            if(word1[j]!=word2[j]){
              if(!adj[word1[j]].count(word2[j])){
                adj[word1[j]].insert(word2[j]);
                inDegree[word2[j]]++;
              }
              break;
            }
          }


        }

        queue<char> q;

        for(auto &[c,deg]:inDegree){
          if(deg==0){
            q.push(c);
          }
        }

        string res = "";

        while(!q.empty()){
          char ch = q.front();
          q.pop();

          res+=ch;

          for(auto &it:adj[ch]){
            inDegree[it]--;
            if(inDegree[it]==0){
              q.push(it);
            }
          }
        }

        return res.size()==inDegree.size() ? res : "";

    }
};
