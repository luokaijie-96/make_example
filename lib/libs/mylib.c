#include "mylib.h"
#include "stdio.h"

void mylib()
{
#ifdef  LIB_TYPE_STATIC    
    printf("This is static mylib()\r\n");
#else
    printf("This is dynamic mylib()\r\n");
#endif
}
