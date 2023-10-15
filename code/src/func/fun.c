/* fun.c */
#include <stdio.h>

void fun()
{

#ifdef MACRO_DEF
    printf("macro definition enable!\n");
#endif


#ifdef COMPILER_IS_ARM_LINUX_GCC
    printf("The compilation target is arm!\n");
#endif

#ifdef COMPILER_IS_LINUX_GCC
    printf("The compilation target is linux!\n");
#endif

    printf("This is fun()!\n");
}

