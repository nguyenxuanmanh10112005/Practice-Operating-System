#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int nthreads = omp_get_num_threads();
        int thread_num = omp_get_thread_num();

        printf("Vao vung song song: %d (thread %d)\n", nthreads, thread_num);

        #pragma omp for
        for (int iter = 0; iter < nthreads; iter++) {
            printf("Thread %d thuc hien lan lap %d\n", thread_num, iter);
        }
    }
    return 0;
}

// Khi thread > core
/*
OpenMp sẽ vẫn tạo đủ số lượng thread theo omp_num_threads
Vd: máy có 4 core thì đặt omp_threads = 8 vẫn tạo ra 8 thread

Nhưng CPU chỉ có 4 core thì chỉ chạy đồng thời tối đa được 4 thread
Các thread dư phải chờ để cpu xử lí nên tốc độ không tăng khi thread > core
*/