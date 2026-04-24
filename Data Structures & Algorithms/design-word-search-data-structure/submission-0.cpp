class TrieNode{
    public:
    TrieNode* children[26];
    bool endofword;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endofword=false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    bool searchWord(TrieNode* r,int i,string word){
         TrieNode* curr = r;

         for(int j=i;j<word.size();j++){
            if(word[j]=='.'){
                for(int ind=0;ind<26;ind++){
                    if(curr->children[ind] && searchWord(curr->children[ind],j+1,word)){
                        return true;
                    }
                }
                return false;
            }

            else{
                if(curr->children[word[j]-'a']==NULL)
                return false;

                curr=curr->children[word[j]-'a'];
            }
         }

         return curr->endofword;
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char &ch: word){
            int i = ch - 'a';

            if(curr->children[i]==NULL){
                curr->children[i]=new TrieNode();
            }

            curr=curr->children[i];
        }

        curr->endofword = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        return searchWord(curr,0,word);
    }

};
