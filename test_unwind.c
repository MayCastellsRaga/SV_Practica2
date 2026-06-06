#include <stdint.h>
#define N 8
void sort (int8_t a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int8_t temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main() {
    int8_t array[N];
    sort(array, N);
    return 0;
}
