class KthLargest {
public:

    int elem;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        elem = k;
        for(auto &it: nums){
          pq.push(it);
          
          if(pq.size()>k)
          pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()>elem)
        pq.pop();

        return pq.top();

        
    }
};
