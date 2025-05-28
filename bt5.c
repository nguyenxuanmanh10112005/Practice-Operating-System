#include <stdio.h>
#include <omp.h>

// Tim max trong mang
// Find value max in array

int main() {
    int a[8] = {3, 7, 2, 9, 5, 8, 1, 6};
    int max = a[0];

    #pragma omp parallel for reduction(max:max)
    for (int i = 1; i < 8; i++) {
        if (a[i] > max)
            max = a[i];
    }

    printf("Gia tri lon nhat: %d\n", max);
    return 0;
}
