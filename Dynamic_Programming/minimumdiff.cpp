
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum / 2; 

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                return totalSum - 2 * j; 
            }
        }

        return totalSum;

