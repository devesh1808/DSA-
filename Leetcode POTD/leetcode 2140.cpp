class Solution
{
public:
    vector<long long> dp;
    long long func(int i, vector<vector<int>> &q)
    {
        if (i >= q.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long choice1 = 0, choice2 = 0;
        choice1 = q[i][0] + func(i + q[i][1] + 1, q);
        choice2 = func(i + 1, q);
        return dp[i] = max(choice1, choice2);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        dp.resize(n + 1, -1);
        return func(0, questions);
    }
};