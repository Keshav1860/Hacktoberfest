class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        vector<int> padded;
        padded.push_back(1);           // Add 1 at the start
        padded.insert(padded.end(), nums.begin(), nums.end()); // Add original nums
        padded.push_back(1);    
        
        int n = padded.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(padded, 1, n - 2, dp);
    }
    int helper(vector<int>& nums, int si, int ei, vector<vector<int>>& dp) 
    {
        if (si > ei) return 0;
        if (dp[si][ei] != -1) return dp[si][ei];

        int maxCoins = 0;
        for (int i = si; i <= ei; i++) {
            int coins = nums[si - 1] * nums[i] * nums[ei + 1];
            coins += helper(nums, si, i - 1, dp);
            coins += helper(nums, i + 1, ei, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[si][ei] = maxCoins;
    }
};
