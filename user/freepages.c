#include "kernel/types.h"
#include "user/user.h"

int main()
{
   printf("Number of free pages: %d\n", freepages());
   return 0;
}