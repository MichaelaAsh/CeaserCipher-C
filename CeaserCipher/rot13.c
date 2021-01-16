#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAIL -1
#define SUCCESS 2

/*==============================================================================*/
char  caeser_cipher (char contents ) {

  char apply_cipher;


  if (contents >= 97  && contents <= 122 ) {

      apply_cipher = contents + 13;
      printf("1st lower = %d\n",apply_cipher);

      if (apply_cipher <= -121 || apply_cipher >= 122) {
        /*  apply_cipher = (apply_cipher) + 204 + 26; */
          apply_cipher = apply_cipher - 26;
          /*printf("2nd lower = %d \n", apply_cipher);*/
    }

      if (apply_cipher < 97) {
        /*  apply_cipher = (apply_cipher) + 204 + 26; */
          apply_cipher = apply_cipher + 26;

      }

  } else if (contents >= 65  && contents <= 90) {

      apply_cipher = contents + 13;
      if (apply_cipher > 90) {
         apply_cipher = apply_cipher - 26;
      }

  } else {
    apply_cipher = contents;
  }

  contents = apply_cipher;

  return contents;
}

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
  char encoded;

  contents = fgetc (original_text);

  while (contents != EOF) {

    encoded = caeser_cipher(contents);
    fputc (encoded, copy_text);
    contents = fgetc (original_text);
  }

  printf("File Encoded \n");
  /* while (fscanf (original_text, "%s", line) != EOF) {
      fprintf(copy_text, "%s", line);

   } */   /*this prints everything one line */

   fclose (copy_text);
   fclose (original_text);

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

} else  {
  return(FAIL);

}



  return (SUCCESS);
}
