long long countGoodIntegers(int n, int k)
{
    int d = ((n + 1) / 2);
    int start = pow(10, d - 1), end = pow(10, d) - 1;
    unordered_set<string> st;
    for (int num = start; num <= end; num++)
    {
        string leftHalf = to_string(num);
        string rightHalf = "";
        if (n & 1)
        {
            for (int i = 0; i < d - 1; i++)
                rightHalf += leftHalf[i];
        }
        else
        {
            for (int i = 0; i < d; i++)
                rightHalf += leftHalf[i];
        }
        reverse(rightHalf.begin(), rightHalf.end());
        string total = leftHalf + rightHalf;
        if (stoll(total) % k == 0)
        {
            sort(total.begin(), total.end());
            st.insert(total);
        }
    }
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i;
    }

    long long res = 0;
    for (string s : st)
    {
        vector<int> cnt(10, 0);
        for (char c : s)
            cnt[c - '0']++;

        long long total = (n - cnt[0]) * fact[n - 1];
        for (int c : cnt)
        {
            if (c > 1)
                total /= fact[c];
        }
        res += total;
    }

    return res;
}