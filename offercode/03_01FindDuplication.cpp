// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
bool duplicate(int nums[], int length, int *duplication)
{
    if (nums == nullptr || length <= 0)
        return false;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] < 0 || nums[i] > length - 1)
            return false;
    }
    for (int i = 0; i < length; i++)
    {
        while (i != nums[i])
        {
            if (nums[i] == nums[nums[i]])
            {
                *duplication = nums[i];
                return true;
            }
            int temp = nums[i];
            nums[i] = nums[nums[i]];
            nums[temp] = temp;
        }
    }
}
// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。
int getDuplicaiton(const int *nums, int length)
{
    if (nums == nullptr || length <= 0)
        return -1;
    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int mid = ((end - start) >> 1) + start;
        int count = countRange(nums, length, start, end);
        if (end == start)
        {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > (mid - start + 1))
            end = mid;
        else
            start = mid + 1;
    }
    return -1;
}
int countRange(const int *nums, int length, int start, int end)
{
    if (nums == nullptr)
        return 0;
    int count = 0;
    for (int i = 0; i < length; i++)
        if (nums[i] >= start && nums[i] <= end)
            count++;
    return count;
}