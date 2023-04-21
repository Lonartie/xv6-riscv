/*
   Requirements: 
      - 1. Parameter: duration in seconds
      - when no parameters: 'User: sleep [seconds]'
*/
#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char** argv) {
   if (argc != 2) {
      printf("User: sleep [seconds]\n");
      exit(1);
   }
   int duration_secs = atoi(argv[1]);
   // the sleep syscall sleeps for n/10 seconds
   sleep(duration_secs * 10);
   exit(0);
}