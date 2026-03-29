class Solution {
public:

    string encode(vector<string>& strs) {

       string encString = "";

       for(const string& str:strs){
        encString += to_string(str.length()) + '#' + str;
       }

       return encString;
    }

    vector<string> decode(string s) {

        vector<string> decStr;
        int i = 0;

        while(i<s.size()){
            int j = i;

            while(s[j]!='#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;

            decStr.push_back(s.substr(i,len));
            i=j;

        }

        return decStr;
        
    }
};
