class Solution
{
public:
    int func(int i, int xr, vector<int> &nums)
    {
        if (i >= nums.size())
            return xr;
        int pick = func(i + 1, xr ^ nums[i], nums);
        int nonpick = func(i + 1, xr, nums);
        return pick + nonpick;
    }
    int subsetXORSum(vector<int> &nums)
    {
        return func(0, 0, nums);
    }
};
