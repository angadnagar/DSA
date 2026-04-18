class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>num){
          maxHeap.push(num);
        }
        else{
          minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()+1){
          int elem = maxHeap.top();
          maxHeap.pop();
          minHeap.push(elem);
        }

        else if(minHeap.size()>maxHeap.size()){
          int elem = minHeap.top();
          minHeap.pop();
          maxHeap.push(elem);
        }

    }
    
    double findMedian() {
        int total = minHeap.size() + maxHeap.size();

        if(total%2 == 1){
          return maxHeap.top();
        }

        return (maxHeap.top()+minHeap.top())/2.0;
    }
};
