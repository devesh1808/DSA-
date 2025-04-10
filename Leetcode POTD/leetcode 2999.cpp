class Solution
{
public:
    long long helper(long long num, string s, int limit)
    {
        string str = to_string(num);
        if (str.length() < s.length())
            return 0;
        int remLen = str.length() - s.length();
        long long cnt = 0;
        string trailStr = str.substr(str.length() - s.length());
        for (int i = 0; i < remLen; i++)
        {
            int dig = str[i] - '0';
            if (dig <= limit)
            {
                cnt += dig * pow(limit + 1, remLen - i - 1);
            }
            else
            {
                cnt += pow(limit + 1, remLen - i);
                return cnt;
            }
        }
        return (trailStr >= s) ? cnt + 1 : cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        return helper(finish, s, limit) - helper(start - 1, s, limit);
    }
};