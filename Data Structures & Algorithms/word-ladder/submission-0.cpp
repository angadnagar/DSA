class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        queue<string> q;

        q.push(beginWord);
        int res = 0;

        while(!q.empty()){
           res++;
           int len = q.size();

           for(int i=0;i<len;i++){
            string word = q.front();
            q.pop();

            if(word==endWord)
            return res;

            for(int j=0;j<word.length();j++){
              char original = word[j];

              for(char ch='a';ch<='z';ch++){

                if(ch==original)
                continue;

                word[j]=ch;

                if(words.find(word)!=words.end()){
                  words.erase(word);
                  q.push(word);
                }
              }
              word[j]=original;
            }
           }
        }

        return 0;
    }
};
