// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数
bool FindInPartiallySortedMatrix(int *matrix, int rows, int cols, int nums)
{
    bool found = false;
    if (matrix != nullptr && rows > 0 && cols > 0)
    {
        int row = 0;
        int col = cols - 1;
        while (row < rows && col < cols)
        {
            if (matrix[row * cols + col] == nums)
            {
                found = true;
                break;
            }
            else if (matrix[row * cols + col] > nums)
                --col;
            else
                ++row;
        }
    }
    return found;
}