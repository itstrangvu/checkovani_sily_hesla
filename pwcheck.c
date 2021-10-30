#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0

/* PRŮCHOD
 * 1. osetreni vstupu programu
 * 2. ulozeni urovne bezpecnosti
 * 3. cteni jednotlivych hesel
 * 4. ulozeni jednotliveho hesla
 * 5. checkovani sily hesla podle urovne bezpecnosti
 * 6. vypsani hesla
 * 7. updatovani statistik
 * 8. vypsani statistik
 */

/* pomocna fce */
bool hasLower(char *pw) {
   bool hasLowerChar = false;
   for (int i = 0; pw[i] != 0; i++) {
      if (pw[i] >= 'a' && pw[i] <= 'z') hasLowerChar = true;
   }
   return hasLowerChar;
}

/* pomocna fce */
bool hasUpper(char *pw) {
   bool hasUpperChar = false;
   for (int i = 0; pw[i] != 0; i++) {
      if (pw[i] >= 'A' && pw[i] <= 'Z') hasUpperChar = true;
   }
   return hasUpperChar;
}

/* pomocna fce */
bool hasNum(char *pw) {
   bool hasNumber = false;
   for (int i = 0; pw[i] != 0; i++) {
      if (pw[i] >= '0' && pw[i] <= '9') hasNumber = true;
   }
   return hasNumber;
}

// /* pomocna fce */
bool hasSpecial(char *pw) {
   bool hasSpecialChar = false;
   for (int i = 0; pw[i] != 0; i++) {
      if (((((pw[i] >= 32) && (pw[i] <= 47)) || ((pw[i] >= 58) && (pw[i] <= 64))) || ((pw[i] >= 91) && (pw[i] <= 96))) || ((pw[i] >= 123 && pw[i] <= 126))) {
         hasSpecialChar = true;
      }
   }
   return hasSpecialChar;
}



bool level1(char *pw, int param) {
   if ((hasLower(pw) == true) && (hasUpper(pw) == true)) {
      return true;
   } else {
      printf("%s nesplňuje 1. úroveň bezpečnosti.\n", pw);
      return false;
   }
}

bool level2(char* pw, int param) {
   switch (param) {
      case 1:
         if (hasLower(pw)) {
            return true;
         }
         break;
      case 2:
         if (hasLower(pw) && hasUpper(pw)) {
            return true;
         }
         break;
      case 3:
         if ((hasLower(pw) && hasUpper(pw)) && hasNum(pw)) {
            return true;
         }
         break;
      case 4:
         if (((hasLower(pw) && hasUpper(pw)) && hasNum(pw)) && hasSpecial(pw)) {
            return true;
         }
         break;
   }
   return false;
}

bool level3(char* pw, int param) {
   return false;
}

bool level4(char* pw, int param) {
   return false;
}

bool over_heslo(char *pw, int level, int param) {
   switch (level) {
      case 1:
         if (level1(pw, param)) {
            return true;
         }
         break;
      case 2:
         if (level2(pw, param)) {
            return true;
         }
         break;
      case 3:
         printf("Ou, level 3 a níž.\n");
         break;
      case 4:
         printf("Safra, level 4 a níž.\n");
         break;
   }
   return false;
}

int main(int argc, char **argv) {
   bool PRINT_STATS;
   int UROVEN, PARAM, MIN, MAX, AVG = 0;
   char stats[] = "--stats";

   /* 1. OSETRENI VSTUPU PROGRAMU */
   if ((argc < 3) || (argc > 4)) {
      fprintf(stderr, "Chybný počet argumentů.\n");
   }
   /* TO-DO
   if ((atoi(argv[0]) < 1) || (atoi(argv[0]) > 4)) {
      fprintf(stderr, "Chybný první argument.");
   }
   if (atoi(argv[1] < 0)) {
      fprintf(stderr, "Chybný druhý argument.\n");
   }
   */
   printf("Treti argument je %s\n", argv[3]);
   if (strcmp(argv[3], stats) == false) {
      printf("Chce to statistiky.\n");
      PRINT_STATS = true;
   } else {
      printf("Nechce to statistiky. A soubor je %s\n", argv[2]);
   }
   /* KONEC 1. OSETRENI VSTUPU PROGRAMU */
   
   /* 2. ULOZENI UROVNE BEZPECNOSTI */ 
   /* Prvni dva argumenty jako konstanty */ 
   UROVEN = atoi(argv[1]);
   printf("Požadovaná úroveň bezpečnosti je %d.\n", UROVEN);
   PARAM = atoi(argv[2]);
   printf("Parametr je %d.\n", PARAM);
   /* KONEC ULOZENI UROVNE BEZPECNOSTI */ 

   /* 3. CTENI JEDNOTLIVYCH HESEL, 4. ULOZENI JEDNOTLIVEHO HESLA, 5. CHECKOVANI PODLE UROVNE */
      int znak;
      char heslo[99]; 
      printf("Hesla jsou:\n");
      while ((znak = getchar()) != EOF) {
         if (znak != '\n') {
            strncat(heslo, &znak, 1);
         } else {
            // 4. ted mam ulozene jednotlive heslo, tak ho 5. overim
            if (over_heslo(heslo, UROVEN, PARAM) == true) {
               printf("%s\n", heslo);
            }
            heslo[0] = '\0';
         }
      }
   /* KONEC CTENI JEDNOTLIVYCH HESEL*/
   return 0;
}