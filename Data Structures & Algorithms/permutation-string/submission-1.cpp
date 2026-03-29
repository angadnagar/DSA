class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26,0);
        vector<int> m2(26,0);

        int len1 = s1.length();
        int len2 = s2.length();

        if(len1>len2)
        return false;


        for(int i=0;i<len1;i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }

        int matches = 0;

        for(int i=0;i<26;i++){
            if(m1[i]==m2[i]){
                matches++;
            }
        }

        int i = 0;
        int j = len1;

        while(j<len2){
            if(matches==26)
            return true;

            int r = s2[j]-'a';
            m2[r]++;
            if(m1[r]==m2[r]){
                matches++;
            }

            else if(m1[r]+1 == m2[r])
            matches--;

            j++;

            int l = s2[i]-'a';
            m2[l]--;

            if(m1[l]==m2[l]){
                matches++;
            }

            else if(m1[l]-1 == m2[l])
            matches--;

            i++;


        }

        return matches==26;
    }
};
