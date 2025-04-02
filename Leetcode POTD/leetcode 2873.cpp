class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long mx = 0;
        for (int i = 0; i < n - 2; i++)
        {
            long long val1 = nums[i];
            for (int j = i + 1; j < n - 1; j++)
            {
                long long val2 = nums[j];
                for (int k = j + 1; k < n; k++)
                {
                    if ((val1 - val2) * nums[k] > mx)
                    {
                        mx = (val1 - val2) * nums[k];
                    }
                }
            }
        }
        return mx;
    }
};