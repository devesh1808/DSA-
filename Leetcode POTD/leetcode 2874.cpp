class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long mx = 0, diff = 0, fmax = 0;
        for (int i = 0; i < n; i++)
        {
            if (diff * nums[i] > mx)
                mx = diff * nums[i];
            if (nums[i] > fmax)
                fmax = nums[i];
            if (fmax - nums[i] > diff)
                diff = fmax - nums[i];
        }
        return mx;
    }
};