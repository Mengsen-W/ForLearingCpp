/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-13 19:42:08
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-13 19:53:59
 */

#include <stdio.h>
// void test01() {
//     extern int a;
//     int a = 0;
//     return;
// }

// void test02() {
//     extern int a;
//     a = 0;
//     return;
// }
extern int a;//写到别的文件后在本文件定义和声明

int main() {
    // test01();
    // test02();
    
    return 0;
}

/*test01
2_2_2.cpp:14:9: error: non-extern declaration of 'a' follows extern declaration
    int a = 0;
        ^
2_2_2.cpp:12:16: note: previous declaration is here
    extern int a;
               ^
1 error generated.
 */

/*test02
C:\Users\ADMINI~1\AppData\Local\Temp\2_2_2-c3c546.o:2_2_2.cpp:(.rdata$.refptr.a[.refptr.a]+0x0):
undefined reference to `a' clang++: error: linker command failed with exit code
1 (use -v to see invocation)
*/
/*
max.c
#include <stdio.h>
外部变量声明
extern int g_X ;
extern int g_Y ;
int max()
{
    return (g_X > g_Y ? g_X : g_Y);
}
main.c
#include <stdio.h>
定义两个全局变量
int g_X=10;
int g_Y=20;
int max();
int main(void)
{
    int result;
    result = max();
    printf("the max value is %d\n",result);
    return 0;
}
*/

/*
* 变量只可以被定义一次，但可以多次声明

 */