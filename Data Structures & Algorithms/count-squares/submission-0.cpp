class CountSquares {
public:
    
    unordered_map<int,unordered_map<int,int>> ptsCount;
    vector<vector<int>> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0];
        int py = point[1];

        for(auto &p:points){
          int x = p[0];
          int y = p[1];
          if(abs(x-px)!=abs(y-py) || px==x || py==y)continue;

          res+=ptsCount[px][y] * ptsCount[x][py];
        }

        return res;
    }
};
