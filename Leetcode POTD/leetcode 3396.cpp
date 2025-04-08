// Brute Force : O(n^2)

// bool isDistinct(unordered_map<int, int> mp)
// {
//     for (auto it : mp)
//     {
//         if (it.second > 1)
//             return false;
//     }
//     return true;
// }
// int minimumOperations(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 1)
//         return 0;
//     if (n == 2)
//         return nums[0] != nums[1] ? 0 : 1;
//     int cnt = 0, i = 0, k = 0;
//     unordered_map<int, int> mp;
//     for (int ele : nums)
//     {
//         mp[ele]++;
//     }
//     if (isDistinct(mp))
//         return cnt;
//     while (i < n)
//     {
//         k += 3;
//         while (i < k)
//         {
//             if (i >= n)
//                 break;
//             mp[nums[i]]--;
//             i++;
//         }
//         cnt++;
//         if (isDistinct(mp))
//             return cnt;
//     }
//     return cnt;
// }

// Better Approach (O(n))

int minimumOperations(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (st.find(nums[i]) != st.end())
            break;
        st.insert(nums[i]);
    }
    return ((i + 1) % 3 == 0) ? (i + 1) / 3 : ((i + 1) / 3) + 1;
}