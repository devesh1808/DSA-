long long countGood(vector<int> &nums, int k)
{
    int n = nums.size();
    long long ans = 0;
    long long pairs = 0;
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    while (j < n)
    {
        if (mp.find(nums[j]) == mp.end())
            mp[nums[j]]++;
        else
        {
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while (pairs >= k)
            {
                ans += (n - j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
        }
        j++;
    }
    return ans;
}