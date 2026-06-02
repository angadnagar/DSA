class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = accumulate(gas.begin(),gas.end(),0);
        int total_cost = accumulate(cost.begin(),cost.end(),0);

        if(total_gas<total_cost)
        return -1;

        int total = 0;
        int res = 0;

        for(int i=0;i<n;i++){
          total+=gas[i]-cost[i];

          if(total<0){
            total=0;
            res=i+1;
          }
        }

        return res;
    }
};
