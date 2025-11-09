class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        vector<int> prefixMax(n); 
        vector<int> suffixMax(n);  
       
        for (int i = 0; i < n; i++) {
            if (i % k == 0) {
                prefixMax[i] = nums[i];
            } else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }
        

        for (int i = n - 1; i >= 0; i--) {
            if ((i + 1) % k == 0 || i == n - 1) {
                suffixMax[i] = nums[i];
            } else {
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
            }
        }

        for (int i = 0; i <= n - k; i++) {
            result.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        }
        
        return result;
    }
};
