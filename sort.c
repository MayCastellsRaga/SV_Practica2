#include <stdint.h>

#define N 12


void swap(int8_t *arr, int i, int j);

void sort (int8_t a[], int size) {
	 for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a, j, j + 1);
        }
    }
}


void swap(int8_t *arr, int i, int j)
{
    int8_t temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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
	for (i = 0; i < N - 1; ++i){
		__CPROVER_assert(array[i] <= array[i + 1], "Array is not sorted");
	}

}

int main() {
	checkSort();
	return 0;
}
