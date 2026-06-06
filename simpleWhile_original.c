#define N 10

int main()
{
  int numbers[N];
  int maxeven;
  int x = 0, i = 0;
  
   maxeven = 1;
   for (i = 0; i < N ; i++) {
     if (numbers[i] % 2 == 0 ) {
        if (maxeven == 1 || maxeven < numbers[i]) {
            maxeven = numbers[i];
        }
     } 
   }
   int i;
   if (maxeven != 1) {
      for (i = 0; i < N; i++) {
        if (numbers[i] % 2 == 0) {
          __CPROVER_assert(maxeven >= numbers[i], "maxeven ha de ser >= que qualsevol nombre parell");
        }
      }
      int found = 0;
      for (i = 0; i < N; i++) { if (numbers[i] == maxeven) found = 1; }
      __CPROVER_assert(found == 1, "maxeven ha d'existir a l'array");
      __CPROVER_assert(maxeven % 2 == 0, "maxeven ha de ser parell");
   }
   else {
      // No hi ha nombres parells: tots són senars
      for (i = 0; i < N; i++) {
         __CPROVER_assert(numbers[i] % 2 != 0, "tots els nombres han de ser senars");
      }
   }
}
