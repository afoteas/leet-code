class KthLargest {
public:
    int k; 
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<>());
        this->nums = nums;
        
    }
    
    int add(int val) {
        nums.insert(
            std::lower_bound( nums.begin(), nums.end(), val, greater<int>() ),
            val 
        );
        return nums.at(k-1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */