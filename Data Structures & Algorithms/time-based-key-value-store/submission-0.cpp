class TimeMap {
public:
    
    unordered_map<string,vector<pair<string,int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
      string ans = "";
        for(auto &it:m[key]){
            if(timestamp>=it.second){
                ans = it.first;
            }
        }

        return ans;
    }
};
