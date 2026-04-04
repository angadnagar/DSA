class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
      string ans = "";
      auto &values = m[key];
      int i = 0;
      int j = values.size()-1;

      while(i<=j){
        int mid = i+(j-i)/2;

        if(values[mid].first <= timestamp){
          ans=values[mid].second;
          i=mid+1;
        }

        else{
          j=mid-1;
        }
      }


      return ans;


    }
};
