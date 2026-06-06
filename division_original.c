#include <stdio.h>

int main( void ) {
  int D,d, r, q;

  __CPROVER_assume( (D < 0) &&  (D >= -600) &&
                   (d >= 0)  );
  r = D; 
  q = 0;
  while ( r < 0 ) {
    __CPROVER_assert(D == d*q + r, "Invariant: D == d*q + r");
    if (r <= -(2*d)) { r = r + (2*d); }
    else { r = r + d; }
    q--;   
  }
  __CPROVER_assert(D == d*q + r, "Postcondicio: D == d*q + r");
  __CPROVER_assert(r >= 0, "Postcondition: r >= 0");
  __CPROVER_assert(r < d, "Postcondition: r < d");
  printf( " quotient: %d,  reminder: %d\n", q, r );
}
