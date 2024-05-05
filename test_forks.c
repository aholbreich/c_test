#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

const int SLEEP_CHILD = 2;
const int SLEEP_PARENT = 1;
const int ROUNDS = 10;

/**
 * Demonstration of fork behavior (Linux)
*/
int main ()
{
   printf ("Starting Process: \n" );
   int i, j;
   pid_t pid;

   pid = fork(); // Now there are two processes running one is parent and another child

   if (pid == 0) // if fork returns 0, so we are in the child process.    
   {
      // Code that will be applied in child only
      for (j=0; j < ROUNDS; j++)
      {
        printf ("Child process:  %d (PID: %d)\n", j, getpid());
        sleep (SLEEP_CHILD);
      }
      printf ("Child process done. \n" );
      exit (0);
   }
   else if (pid > 0)
   {
      //if fork returns 1, we are in the parent process.
      for (i=0; i < ROUNDS; i++)
      {
         printf ("Parent process: %d (PID: %d)\n", i, getpid());
         sleep (SLEEP_PARENT);
      }
      
      printf ("Parent process done\n" );
      exit (0);

   }
   else
   {
      fprintf (stderr, "Error");
      exit (1);
   }
   return 0;
}