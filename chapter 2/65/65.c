/*
 * 第65题（四星）：实现函数：当给定的数中含有奇数个1返回1，否则返回0
 * 且遵循位级整数编码规则，且最多包含12个算术运算符、位运算和逻辑运算
*/

#include <stdio.h>
#include <stdlib.h>

int odd_ones(unsigned x)
{
    /*
     * 由于偶数个1时结果为0，奇数个1时结果为1
     * 因此考虑使用异或运算，采用以下方法
     * 1.将原数字右移一位并与原数字做异或运算
     * 得到的新数字的第i位代表原数字的第i位与第i+1位的‘1’的个数的奇偶性
     * 2.将得到的数字右移两位并作异或运算
     * 得到的新数字的第i位代表原数字的第i、i+1、i+2、i+3位的‘1’的个数奇偶性
     * 3.每次右移的数目是之前的两倍，得到的新数字的第i位统计的奇偶性的数目也翻倍
    */
    x ^= (x >> 1);
    x ^= (x >> 2);
    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);

    return x & 0x1;
}

int main()
{
    printf("%d,%d", odd_ones(0x5), odd_ones(0xff2));
    system("pause");
}