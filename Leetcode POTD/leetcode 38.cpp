class Solution
{
public:
    // 3 => "11"
    string helper(string s)
    {
        string ans = "";
        int sz = s.length();
        int cnt = 1;
        for (int i = 1; i < sz; i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += to_string(cnt) + s[i - 1];
                cnt = 1;
            }
            else
                cnt++;
        }
        ans += to_string(cnt) + s[sz - 1];
        return ans;
    }
    string countAndSay(int n)
    {
        vector<string> dp(n + 1);
        dp[1] = "1";
        for (int i = 2; i <= n; i++)
        {
            dp[i] = helper(dp[i - 1]);
        }
        return dp[n];
    }
};