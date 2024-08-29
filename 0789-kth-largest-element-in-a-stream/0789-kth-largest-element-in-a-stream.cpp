// class KthLargest {
// public:
//     int k; 
//     vector<int> nums;
//     KthLargest(int k, vector<int>& nums) {
//         this->k = k;
//         sort(nums.begin(), nums.end(), greater<>());
//         this->nums = nums;
        
//     }
    
//     int add(int val) {
//         nums.insert(
//             std::lower_bound( nums.begin(), nums.end(), val, greater<int>() ),
//             val 
//         );
//         return nums.at(k-1);
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


 class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int pqSize = 0;
    int K = 0;
    KthLargest(int k, vector<int>& nums) {
        if(nums.size()>k) sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int size = min(k, n);
        for(int i=0; i<size; i++){
            pq.push(nums[i]);
        }
        pqSize = pq.size();
        K = k;
    }
    
    int add(int val) {
        if(pq.empty()){
            pq.push(val);
            pqSize++;
            return val;
        }
        if(pqSize<K){
            pq.push(val);
            pqSize++;
        }else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};