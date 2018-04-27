#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

const int SLEEP_CHILD = 3;
const int SLEEP_PARENT = 1;
const int ROUNDS = 10;

int main ()
{
   printf ("Starting Process: " );
   int i, j;
   pid_t pid;

   pid = fork();

   if (pid == 0)
   {
      //if fork returnes 0, we are in the child process.
       
      for (j=0; j < ROUNDS; j++)
      {
        printf ("Childprocess:  %d (PID: %d)\n", j, getpid());
        sleep (SLEEP_CHILD);
      }
      exit (0);
   }
   else if (pid > 0)
   {
      //if fork returnes 1, we are in the Parent process.
      for (i=0; i < ROUNDS; i++)
      {
         printf ("Parentprocess: %d (PID: %d)\n", i, getpid());
         sleep (SLEEP_PARENT);
      }
   }
   else
   {
      fprintf (stderr, "Error");
      exit (1);
   }
   return 0;
}