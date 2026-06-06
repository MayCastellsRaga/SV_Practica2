#include <stdio.h>

int main( void ) {
  int D,d, r, q;

  // FIX: canviat d >= 0 per d > 0 per evitar bucle infinit quan d=0 (unwinding realista)
  __CPROVER_assume( (D < 0) &&  (D >= -600) && (d > 0) );
  r = D; 
  q = 0;
  while ( r < 0 ) {
    __CPROVER_assert(D == d*q + r, "Invariant: D == d*q + r");
    
    // FIX: s'ha modificat per evitar l'overflow de 2*d
    // En lloc de r <= -(2*d), usem r + d <= -d
    if (r + d <= -d) { 
        r = r + d;
        r = r + d; 
        q = q - 2; // FIX: el quocient s'ha de reduir en 2
    } else { 
        r = r + d; 
        q = q - 1;
    }
  }

  // Postcondicions de la divisió entera
  __CPROVER_assert(D == d*q + r, "Postcondicio: D == d*q + r");
  __CPROVER_assert(r >= 0, "Postcondicio: residu >= 0");
  __CPROVER_assert(r < d, "Postcondicio: residu < d");

  printf( " quotient: %d,  reminder: %d\n", q, r );
}
