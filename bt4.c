#include <stdio.h>
#include <omp.h>

// Nhan ma tran voi vector
// Multiply matrix with vector

int main() {
    int M = 3, N = 3;
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int x[3] = {1, 2, 3};
    int y[3] = {0};

    #pragma omp parallel for
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    printf("Vector ket qua:\n");
    for (int i = 0; i < M; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}
