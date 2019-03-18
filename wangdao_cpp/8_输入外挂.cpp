bool readint(int &ret)
{                  //输入整数,并将整数保存在引用变量ret中
    int sgn;       //符号
    char c;        //字符
    c = getchar(); //读入字符
    if (c == EOF)
        return false; //若达到文件尾返回true
    while (c != '-' && c < '0' || c > '9')
        c = getchar();                //跳过不为整数的部分
    sgn = (c == '-') ? -1 : 1;        //若出现负号
    ret = (c == '-') ? 0 : (c - '0'); //若未出现负号
    while ((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'); //计算连续几个字符 组成数字的数值
    ret *= sgn;                     //乘上符号位
    return true;                    //读入成功返回true
}
bool readdouble(double &ret)
{                     //读入浮点数,结果保存在引用变量ret中
    int sgn;          //符号位
    double bit = 0.1; //小数点后数位的权重
    char c;           //字符
    c = getchar();    //读入字符
    if (c == EOF)
        return false; //到达文件尾返回false
    while (c != '-' && c != '.' && (c < '0' || c > '9'))
        c = getchar(); //跳过之前不为数字的部
    分
        sgn = (c == '-') ? -1 : 1;    //若出现负号
    ret = (c == '-') ? 0 : (c - '0'); //若不出现负号
    while ((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'); //计算整数位
    if (c == ' ' || c == '\n')
    {
        ret *= sgn;
        return true;
    } //若不存在小数位
    while ((c = getchar()) >= '0' && c <= '9')
        ret += (c - '0') * bit, bit /= 10; //计算小数位
    ret *= sgn;                            //乘符号位
    return true;                           //读入成功,返回true
}