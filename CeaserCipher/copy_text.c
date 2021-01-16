#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAIL -1
#define SUCCESS 2

/*==============================================================================*/
/* takes input from file and writes to another file */
void read_and_copy_file ( char *original_input, char *copy_input) {
  FILE *original_text = fopen (original_input, "r");
  FILE *copy_text = fopen (copy_input, "w");
  char line[45]; /* max length of a word */

  if (original_text == NULL || copy_text == NULL) { /* error check */
    printf("Invalid File\n");
    exit (FAIL);
  }

  char contents;

  contents = fgetc (original_text);

  while (contents != EOF) {
    fputc (contents, copy_text);
    contents = fgetc (original_text);
  }

  printf("File Copied \n");
  /* while (fscanf (original_text, "%s", line) != EOF) {
      fprintf(copy_text, "%s", line);

   } */   /*this prints everything one line */

   fclose (copy_text);
   fclose (original_text);


}

/*==============================================================================*/
/*takes input from file and prints to stdin */
void read_and_copy_stdout( char *original_input) {

  FILE *original_text = fopen (original_input, "r");
  char line[45]; /* max length of a word */

  if (original_text == NULL) { /* error check */
    printf("Invalid File\n");
    exit (FAIL);
  }


  /*  while (fgets (line, 45, original_text) != NULL) {
       printf("%s ", line);
    } */

    char contents;
    char encoded;

    contents = fgetc (original_text);

    while (contents != EOF) {

      printf ("%c", contents);
      contents = fgetc (original_text);
    }

   fclose (original_text);

}

/*==============================================================================*/
void stdin_stdout ( ) { /* takes input from stdin and prints from stdin */

  char original_input[500];

  fgets (original_input, 500, stdin);
  printf("%s", original_input);

}

/*==============================================================================*/

int main ( int argc, char *argv[]) {

/*  FILE *original_text;
  FILE*copy_text; */

  char original_input[200];
  char copy_input[200];



if (argc >= 3 ) { /* copy the file (original_text)  to another file (copy_text) */

  strcpy (original_input, argv[1]);
  strcpy(copy_input, argv[2]);
  read_and_copy_file(original_input, copy_input);

}  else if (argc >= 2) { /* copy the file  (original_text) to stdout instead */

  strcpy (original_input, argv[1]);
  read_and_copy_stdout(original_input);

} else  {
  stdin_stdout();

}



  return (SUCCESS);
}
