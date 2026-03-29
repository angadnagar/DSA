class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;

        int len1 = s.length();
        int len2 = t.length();

        if(len1!=len2)
        return false;

        for(int i=0;i<len1;i++){
            m[s[i]]++;
        }

        for(int i=0;i<len1;i++){
            if(m.find(t[i])==m.end())
            return false;

            m[t[i]]--;
        }

        for(int i=0;i<len1;i++){
            if(m[s[i]])
            return false;
        }

        return true;
    }
};
