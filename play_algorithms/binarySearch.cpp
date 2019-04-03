#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "MyUtil.h"
using namespace std;

template <typename T>
int binarySearch(T arr[], int n, int target)
{
    int l = 0, r = n - 1; //边界 限定清楚lr的实际意义 在 l r之间寻找target
    while (l <= r)        //lr之间依然是有效的
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        if (target > arr[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
    int n = 1000000;
    int *data = MyUtil::generateOrderedArray(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; i++)
        assert(i == binarySearch(data, n, i));
    clock_t endTime = clock();
    cout << "binarySearch test complate." << endl;
    cout << "Time cost:" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}