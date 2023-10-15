/* libmylib.so */
// mylib()函数,打印This is mylib()！
//
/* main.c */
#include "fun.h"
#include "mylib.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{ 
    fun();
#ifdef INCLUDE_FLAG
    printf("include instruction flag!\r\n");
#endif
    //mylib();
    return 0; 
}
