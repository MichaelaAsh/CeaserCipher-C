#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL -1
#define SUCCESS 2
#define ENTER 10
#define MAX 13

#define L_A 97
#define L_Z 122
#define U_A 65
#define U_Z 90
#define ENDOFALPH 26

/*==============================================================================*/
char  caeser_cipher (char contents, int shift ) { /* only works for number below 13  that are positive */
                                                  /* need to adjust for upper case letter to for negative */
  char apply_cipher;

  if (contents >= L_A  && contents <= L_Z ) {

      apply_cipher = contents + shift;
      if (apply_cipher <= -121 || apply_cipher >= L_Z) {
          apply_cipher = apply_cipher - ENDOFALPH;
      }

      if (apply_cipher < L_A) {
          apply_cipher = apply_cipher + ENDOFALPH;
      }

  } else if (contents >= U_A  && contents <= U_Z) {

      apply_cipher = contents + shift;
      if (apply_cipher > U_Z) {
         apply_cipher = apply_cipher - ENDOFALPH;
      }

  } else {
    apply_cipher = contents;
  }

  contents = apply_cipher;

  return contents;
}

/*==============================================================================*/
char  pos_cipher (char contents, int shift ) { /* only works for numbers above 13  that are positive */
                                                  /* have corrector to adjust checks for lower case */

  char apply_cipher;

  int corrector= 0;

  if (shift > MAX) {
     corrector = shift - MAX;
  }

  if (contents >= L_A  && contents <= L_Z ) {

      apply_cipher = contents + shift;
      if (apply_cipher <= (-121+corrector)|| apply_cipher >= L_Z) {
          apply_cipher = apply_cipher - ENDOFALPH;
       }

      if (apply_cipher < L_A) {
          apply_cipher = apply_cipher + ENDOFALPH;
      }

  } else if (contents >= U_A  && contents <= U_Z) {

      apply_cipher = contents + shift;
      if (apply_cipher > U_Z) {
         printf(" 1nd = %d   %c\n", apply_cipher, apply_cipher);
         apply_cipher = apply_cipher - ENDOFALPH;
         printf(" 2nd = %d  %c\n", apply_cipher, apply_cipher);
         putchar('\n');
      }

  } else {
    apply_cipher = contents;
  }

  contents = apply_cipher;
  printf(" contents = %d   %c\n", contents, contents);

  return contents;
}

/*==============================================================================*/
char  neg_cipher (char contents, int shift ) { /* only works for numbers above 13  that are positive */


    if (contents >= L_A && contents <= L_Z) {
        contents = contents + shift;
        if (contents > L_Z) {
            contents = contents - L_Z + L_A - 1;
        } else if(contents < L_A) {
            contents  = contents + ENDOFALPH;
        }

    } else if (contents >= U_A && contents <= U_Z) {
        contents = contents + shift;
        if (contents > U_Z) {
            contents = contents - U_Z + U_A - 1;
        } else if(contents < U_A) {
            contents = contents + ENDOFALPH;
        }

    }


  return contents;
}

/*==============================================================================*/
/* takes input from file and writes to another file */
void read_and_copy_file ( char *original_input, char *copy_input, int shift) {

  FILE *original_text = fopen (original_input, "r");
  FILE *copy_text = fopen (copy_input, "w");

  if (original_text == NULL || copy_text == NULL) { /* error check */
    printf("Invalid File\n");
    exit (FAIL);
  }

  char contents;
  char encoded;

  contents = fgetc (original_text);


  while (contents != EOF) {
    if (shift > MAX) {
       encoded =  pos_cipher(contents, shift);
    } else if (shift >= 0 && shift <= MAX) {
      encoded = caeser_cipher(contents, shift);
    } else if (shift < 0) {
      encoded = neg_cipher(contents, shift);
    }

    fputc (encoded, copy_text);
    contents = fgetc (original_text);
  }

  printf("File Encoded \n");

   fclose (copy_text);
   fclose (original_text);

}

/*==============================================================================*/
/*takes input from file and prints to stdin */
void read_and_copy_stdout( char *original_input, int shift) {

  FILE *original_text = fopen (original_input, "r");

  if (original_text == NULL) { /* error check */
    printf("Invalid File\n");
    exit (FAIL);
  }


  char contents;
  char encoded;

  contents = fgetc (original_text);

  while (contents != EOF) {
    if (shift > MAX) {
       encoded =  pos_cipher(contents, shift);
    } else if (shift >= 0 && shift <= MAX) {
      encoded = caeser_cipher(contents, shift);
    } else if (shift < 0) {
      encoded = neg_cipher(contents, shift);
    }

    printf ("%c", encoded);
    contents = fgetc (original_text);
  }


   printf("\n\n");
   printf("File Encoded \n");
   fclose (original_text);

}

/*==============================================================================*/
void stdin_stdout ( int shift ) { /* takes input from stdin and prints from stdin */

  char contents;
  char encoded;

  contents = fgetc (stdin);

  while (contents != ENTER) {
    if (shift > MAX) {
       encoded =  pos_cipher(contents, shift);
    } else if (shift >= 0 && shift <= MAX) {
      encoded = caeser_cipher(contents, shift);
    } else if (shift < 0) {
      encoded = neg_cipher(contents, shift);
    }

    printf ("%c", encoded);
    contents = fgetc (stdin);
  }

  printf("\n\n");
  printf("Message Encoded \n");


}

/*==============================================================================*/
void stdin_file ( char *copy_input, int shift) { /* takes input from stdin and prints from file */

  FILE *copy_text = fopen (copy_input, "w");

  if (copy_text == NULL) { /* error check */
    printf("Invalid File\n");
    exit (FAIL);
  }

  char contents;
  char encoded;

  contents = fgetc (stdin);

  while (contents != ENTER) { /* while the user doesn't hit enter */ 
      if (shift > MAX) {
         encoded =  pos_cipher(contents, shift);
      } else if (shift >= 0 && shift <= MAX) {
        encoded = caeser_cipher(contents, shift);
      } else if (shift < 0) {
        encoded = neg_cipher(contents, shift);
      }

      fputc (encoded, copy_text);
      contents = fgetc (stdin);
  }

  printf("\n\n");
  printf("File Encoded \n");
  fclose (copy_text);


}
/*==============================================================================*/
