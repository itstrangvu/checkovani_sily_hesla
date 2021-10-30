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

bool over_heslo(char* pw, int level, int param) {
   switch (level) {
      case 1:
         printf("Cajk, level 1 a níž.\n");
         break;
      case 2:
         printf("Hm, level 2 a níž.\n");
         break;
      case 3:
         printf("Ou, level 3 a níž.\n");
         break;
      case 4:
         printf("Safra, level 4 a níž.\n");
         break;
   }
   return true;
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
            over_heslo(heslo, UROVEN, PARAM);
            printf("%s\n", heslo);
            heslo[0] = '\0';
         }
      }
   /* KONEC CTENI JEDNOTLIVYCH HESEL*/
   return 0;
}