const int MOD = (1e9 + 7);

long long power(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * x) % MOD;
            n--;
        }
        else
        {
            x = (x * x) % MOD;
            n /= 2;
        }
    }
    return ans;
}
int countGoodNumbers(long long n)
{
    if (n == 1)
        return 5;
    long long evenIndices = (n + 1) / 2;
    long long oddIndices = n / 2;
    long long ans = (power(5, evenIndices) * power(4, oddIndices)) % MOD;
    return ans;
}