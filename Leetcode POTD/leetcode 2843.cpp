int countSymmetricIntegers(int low, int high)
{
    int noOfSymmetric = 0;
    for (int num = low; num <= high; num++)
    {
        string str = to_string(num);
        int sz = str.length();
        if (sz & 1 == 1)
            continue;
        int leftSum = 0, rightSum = 0;
        int i = 0, j = sz - 1;
        while (i < j)
        {
            leftSum += str[i++];
            rightSum += str[j--];
        }
        noOfSymmetric += (leftSum == rightSum);
    }
    return noOfSymmetric;
}