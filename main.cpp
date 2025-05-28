#include <stdio.h>
#include <omp.h>

void outside_parallel() {
    int n = omp_get_thread_num();
    printf("Outside the parallel region - Thread %d\n", n);
}

void inside_parallel() {
    #pragma omp parallel
    {
        int n = omp_get_thread_num();
        printf("Inside the parallel region - Thread %d\n", n);
    }
}

void nested_outside_parallel() {
    int n = omp_get_thread_num();
    printf("Nested function outside parallel - Thread %d\n", n);
}

void nested_inside_parallel() {
    #pragma omp parallel
    {   
        int n = omp_get_thread_num();
        printf("Nested function inside parallel - Thread %d\n", n);
    }
}

int main() {

    outside_parallel();

    inside_parallel();

    #pragma omp parallel
    {
        nested_outside_parallel();  
        nested_inside_parallel();   
    }

    return 0;
}
