#include <stdio.h>
#include <omp.h>

void f() {
    int i;
    #pragma omp for
    for (i = 0; i < 8; i++) {
        printf("Thread %d xu li i = %d\n", omp_get_thread_num(), i);
    }
}

int main() {
    omp_set_nested(1);

    printf("Goi f() ngoai vung song song:\n");
    f();

    printf("\nGoi f() trong vungsong song:\n");
    #pragma omp parallel
    {
        f();
    }

    return 0;
}
