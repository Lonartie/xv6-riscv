#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
#include "user/user.h"

const char* state2str(enum procstate);

int main()
{
   uint64 num = ps(0);
   
   struct proc_info* pinfo = malloc(sizeof(struct proc_info) * num);
   ps(pinfo);

   for (uint64 i = 0; i < num; i++) {
      printf("%s\t%d\t%s\n", pinfo[i].name, pinfo[i].pid, state2str(pinfo[i].state));
   }

   printf("Number of processes: %d\n", num);

   return 0;
}

const char* state2str(enum procstate state)
{
   if (state == UNUSED)     return "unused";
   if (state == USED)       return "used";
   if (state == SLEEPING)   return "sleep";
   if (state == RUNNABLE)   return "runnable";
   if (state == RUNNING)    return "running";
   if (state == ZOMBIE)     return "zombie";
   return "UNKNOWN";
}