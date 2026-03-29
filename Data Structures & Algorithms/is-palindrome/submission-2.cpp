class Solution {
public:

    bool isalphaNum(char ch){
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') );
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        while(i<=j){
            while(i<j && !isalphaNum(s[i]))
            i++;

            while(j>i && !isalphaNum(s[j]))
            j--;

            if(tolower(s[i])!=tolower(s[j]))
            return false;

            i++;
            j--;
        }

        return true;



    }
};
