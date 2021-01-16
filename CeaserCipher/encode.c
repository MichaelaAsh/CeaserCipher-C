#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#define FAIL -1
#define SUCCESS 2


int main ( int argc, char *argv[]) {

  char original_input[200];
  char copy_input[200];
  int shift = 13;



if (argc > 4 ) { /* copy the file (original_text)  to another file (copy_text) */

   if (strcmp(argv[3],"-O") == 0) { /* fix later */
     printf("Error no space between file \n");
     exit(FAIL);
   }

  if (strcmp(argv[2],"-F") == 0) { /* checks if the -F is there for the next argument therefore shift is there for argv[1] */
    shift = atoi (argv[1]);
    if (shift < -26 ||  shift > 26) { /* program can only hande a shift between -26 and 26 (inlcusive)*/
       printf("Shift is too large\n");
       exit(FAIL);
    }

    strcpy (original_input, argv[3]);
    strcpy(copy_input, argv[5]);
  } else {
    shift = 13;
    strcpy (original_input, argv[2]);
    strcpy(copy_input, argv[3]);
  }

  read_and_copy_file(original_input, copy_input, shift);

} else if (argc > 2) { /* copy the file  (original_text) to stdout instead */

      if (strcmp(argv[2],"-O") == 0) { /* fix later */
        printf("Error no space between file \n");
        exit(FAIL);
      }

    if (strcmp (argv[2], "-F") == 0) { /* checks if the -F is there for the next argument therefore shift is there for argv[1] */
      shift = atoi (argv[1]);
      if (shift < -26 ||  shift > 26) { /* program can only hande a shift between -26 and 26 (inlcusive)*/
         printf("Shift is too large\n");
         exit(FAIL);
      }
      strcpy (original_input, argv[3]);
      read_and_copy_stdout(original_input, shift);
    } else if  ( strcmp (argv[2], "-O") == 0) {
      shift = atoi (argv[1]);
      if (shift < -26 ||  shift > 26) { /* program can only hande a shift between -26 and 26 (inlcusive)*/
         printf("Shift is too large\n");
         exit(FAIL);
      }
      strcpy (copy_input, argv[3]);
      stdin_file(copy_input, shift); /*need write to file  from stdin*/

    } else if (strcmp (argv[1],"-F") == 0) { /* checks if the -F is there for the next argument therefore shift is there for argv[1] */
      shift = 13;
      strcpy (original_input, argv[2]);
      read_and_copy_stdout(original_input, shift);

    } else if (strcmp(argv[1],"-O") == 0 )  {
      shift = 13;
      strcpy (copy_input, argv[2]);
      stdin_file(copy_input, shift);  /* need to write to file from stdin */
    }

  } else  if (argc > 1) {
     shift = atoi (argv[1]);
     if (shift < -26 ||  shift > 26) { /* program can only hande a shift between -26 and 26 (inlcusive)*/
        printf("Shift is too large\n");
        exit(FAIL);
     }
     stdin_stdout(shift);
  } else if (argc > 0) {
    stdin_stdout(shift);

  }



  return (SUCCESS);
}
