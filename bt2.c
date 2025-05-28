#include <stdio.h> 
#include <omp.h>

// Dem so chan trong mot mang
int main() {

    int a[10] = {1, 4, 6, 3, 7, 9, 2, 5, 10, 8};

    int count = 0;

    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < 10; i++) {
        if(a[i] % 2 == 0) {
            count ++;
        }
    }

    printf("So luong so chan: %d", count);
    
    return 0;
}