vector<double> runningMedian(vector<int> a) {
     vector<double> medians;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : a) 
    {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        double median;
        if (maxHeap.size() == minHeap.size()) {
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            median = maxHeap.top();
        }
        medians.push_back(median);
    }
    
    return medians;


}
