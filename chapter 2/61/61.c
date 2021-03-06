/*
 * 第61题：写出c表达式，在以下情况为1，其余情况为0
 * 1.任何位都为1
 * 2.任何位都为0
 * 3.最低有效字节为1
 * 4.最高有效字节为0
 * 其中，x为int类型
*/

#include <stdio.h>
#include <stdlib.h>

int test(int x)
{
    return !(~x) || !x || !((x ^ 0xff) << ((sizeof(int) - 1) << 3)) || !(x >> ((sizeof(int) - 1) << 3));
    /*
     * 第一种情况全是1直接按位取反再取反就得到1
     * 第二种情况全是0直接取反
     * 第三种情况最低位全是1，先与0xff异或，如果最低位全是1则得到的结果最低位全是0
     * 再移位得到全0，注意要移动3*8位
     * 也可以 !((x^0xff)&0xff)
     * 第四种情况最高位全是0，直接移位即可
    */
}

int main()
{
    printf("%d", test(0x003454f1));

    system("pause");
}