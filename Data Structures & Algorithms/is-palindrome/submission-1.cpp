class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        int i=0;
        int n = s.length();
        while(i<n){

            while(s[i]==' '){
                i++;
            }

            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]
            <='9')){
                str+=s[i];
            }


            i++;
        }

        transform(str.begin(),str.end(),str.begin(),::tolower);
 
        int len = str.length();
        i=0;
        int j = len-1;

        while(i<=j){
            if(str[i]!=str[j])
            return false;

            i++;
            j--;
        }

        return true;
    }
};
