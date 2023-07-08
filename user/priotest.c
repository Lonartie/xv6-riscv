#include "kernel/types.h"
#include "user/user.h"

void child_stuff(void);

int main(int argc, char** argv) {

   int forks = 2;

   if (argc == 2) {
      forks = atoi(argv[1]);
   }
   
   printf("Creating %d forks\n", forks);
   
   for (int i = 0; i < forks; i++) {
      int pid = fork();

      if (pid == 0) {
         child_stuff();

         // child needs to exit now
         // otherwise this creates a type of fork bomb
         exit(0);
      }
   }

   return 0;
}

// force the compiler to not optimize this variable
volatile int test = 0;

void child_stuff(void) {
   int pid = getpid();
   if (pid % 2 == 0) {
      setpriority(70);
   } else {
      setpriority(20);
   }

   // doing some work
   int i = 0;
   while (i < 1e20) {
      i++;
      // because the compiler thinks this variable may change in another thread
      // it will not optimize it and therefore the loop will not be optimized away
      test++;
   }
}