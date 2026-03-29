class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        unordered_map<char,int> tCount;
        unordered_map<char,int> windowCount;

        for(int i=0;i<len2;i++){
            tCount[t[i]]++;
        }

        int l = 0;
        int r = 0;

        pair<int,int> res= {-1,-1};

        int mini = INT_MAX;

        int have = 0;
        int need = tCount.size();

        while(r<len1){
            windowCount[s[r]]++;
            
            if(tCount.count(s[r]) && tCount[s[r]]==windowCount[s[r]]){
                have++;
            }

            while(have==need){
               if(r-l+1 < mini){
                mini=r-l+1;
                res={l,r};
               }

               windowCount[s[l]]--;
               if(tCount.count(s[l]) && windowCount[s[l]]<tCount[s[l]]){
                have--;
               }
               l++;
            }

            r++;

        }




        return mini == INT_MAX ? "" : s.substr(res.first,mini);
    }
};
