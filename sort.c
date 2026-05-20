#include <stdint.h>

#define N 8

void sort (int8_t a[], int size) {
	// write your favorite sorting algorithm

}

void checkSort() {

 	int8_t	array[N];
 	int i;
	for (i = 0; i < N; ++i){
      // Assume numbers in array are integers in range [-20,20]
	  __CPROVER_assume((array[i] <= -20) && (array[i] <= 20));
	}

	sort (array, N);

	// write the assertions to check that the array is sorted

}
