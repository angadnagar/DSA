class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int total = m*n;

        vector<int> ans;

        int sum=0;
        int topRow = 0;
        int rightCol = n-1;
        int bottomRow = m-1;
        int leftCol = 0;

        while(sum<total){
          for(int j=leftCol;sum<total && j<=rightCol;j++){
            sum++;
            ans.push_back(matrix[topRow][j]);
          }
          topRow++;

          for(int i=topRow;sum<total && i<=bottomRow;i++){
            sum++;
            ans.push_back(matrix[i][rightCol]);
          }

          rightCol--;

          for(int j=rightCol;sum<total && j>=leftCol;j--){
            sum++;
            ans.push_back(matrix[bottomRow][j]);
          }

          bottomRow--;

          for(int i=bottomRow;sum<total && i>=topRow;i--){
            sum++;
            ans.push_back(matrix[i][leftCol]);
          }

          leftCol++;
           
        }

        return ans;
    }
};
