#include <stdio.h>
#include <omp.h>

void outside_parallel() {
    int n = omp_get_thread_num();
    printf("Ben ngoai vung song song - Thread %d\n", n);
}

void inside_parallel() {
    #pragma omp parallel
    {
        int n = omp_get_thread_num();
        printf("Ben trong vung song song - Thread %d\n", n);
    }
}

void nested_outside_parallel() {
    int n = omp_get_thread_num();
    printf("Ham con ben ngoai song song - Thread %d\n", n);
}

void nested_inside_parallel() {
    #pragma omp parallel
    {   
        int n = omp_get_thread_num();
        printf("Ham con ben trong song song - Thread %d\n", n);
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