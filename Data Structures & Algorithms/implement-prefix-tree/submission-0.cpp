class TrieNode{
    public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char &ch:word){
            int i = ch-'a';
            if(curr->children[i] == NULL){
                curr->children[i] = new TrieNode();
            }
            curr=curr->children[i];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char &ch: word){
            int i = ch-'a';
            if(curr->children[i]==NULL)
            return false;

            curr=curr->children[i];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char &ch: prefix){
            int i = ch-'a';
            if(curr->children[i]==NULL)
            return false;

            curr=curr->children[i];
        }

        return true;
    }
};
