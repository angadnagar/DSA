class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.empty())
        return "";

       int n = strs.size();

       vector<int> sizes(n);


       for(int i=0;i<n;i++){
        sizes[i]=strs[i].length();
       }

       string encStr = "";

       for(auto& it:sizes){
        encStr+=to_string(it)+',';
       }
       encStr+='#';

       for(int i=0;i<n;i++){
        encStr+=strs[i];
       }

       return encStr;
    }

    vector<string> decode(string s) {

        if(s.empty())
        return {};

        
        vector<int> sizes;
        vector<string> decStr;

        int i = 0;

        while(s[i]!='#'){

            string num = "";
            
            while(s[i]!=','){
                num += s[i];
                i++; 
            }

            int sizeNum = stoi(num);
            sizes.push_back(sizeNum);
            i++;
        }
        i++;


        for(auto &it:sizes){
           decStr.push_back(s.substr(i,it));
           i+=it;
        }

        return decStr;
        
    }
};
