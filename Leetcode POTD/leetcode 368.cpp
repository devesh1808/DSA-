class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        vector<int> ans;
        int LIS = *max_element(dp.begin(), dp.end());
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == LIS && (ans.size() == 0 || ans[ans.size() - 1] % nums[i] == 0))
            {
                ans.push_back(nums[i]);
                LIS--;
            }
        }
        reverse(nums.begin(), nums.end());
        return ans;
    }
};
