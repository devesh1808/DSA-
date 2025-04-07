class Solution
{
public:
    vector<vector<int>> dp;
    bool func(int i, int sum, vector<int> &nums)
    {
        if (i >= nums.size())
            return sum == 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        bool pick = false, nonPick = false;
        if (nums[i] <= sum)
            pick = func(i + 1, sum - nums[i], nums);
        nonPick = func(i + 1, sum, nums);
        return dp[i][sum] = pick || nonPick;
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int ele : nums)
            sum += ele;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        dp.resize(n, vector<int>(sum + 1, -1));
        return func(0, sum, nums);
    }
};