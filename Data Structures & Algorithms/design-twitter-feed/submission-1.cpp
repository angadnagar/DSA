class Twitter {
public:

    unordered_map<int,set<int>> followMap;
    unordered_map<int,vector<pair<int,int>>> userToTweets;
    int count;
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        userToTweets[userId].push_back({count,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int,int>> pq;

        vector<int> ans;

        for(auto &it:userToTweets){
          if(it.first == userId || followMap[userId].find(it.first)!=followMap[userId].end()){
            for(auto &j:it.second){
              pq.push({j.first,j.second});
            }
          }
        }

        int cnt = 10;

        while(!pq.empty() && cnt > 0){
          cnt--;
          ans.push_back(pq.top().second);
          pq.pop();

        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
