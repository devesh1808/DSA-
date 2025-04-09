int minOperations(vector<int> &nums, int k)
{
    int smallEle = *min_element(nums.begin(), nums.end());
    if (k > smallEle)
        return -1;
    unordered_map<int, int> mp;
    for (int ele : nums)
        mp[ele]++;
    return smallEle == k ? (mp.size() - 1) : (mp.size());
}