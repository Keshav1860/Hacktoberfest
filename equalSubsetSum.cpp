class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        if (tsum % 2 != 0) return false; // Odd sum? No chance, bro!

        int target = tsum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // You can always make sum 0 (by picking nothing!)

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
