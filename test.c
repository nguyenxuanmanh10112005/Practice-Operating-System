#include <stdio.h>
#include <omp.h>

//#pragma omp parallel :  tạo nhiều luồng chạy song song
//#pragma omp for : chia nhỏ vòng lặp cho các luồng hiện có
//#prama omp parallel for: viết gộp 2 cái trên

// 1
/*
    #prama omp parallel : tạo nhiều luồng chạy cùng lúc
    Khi gặp dòng này thì chương trình sẽ tạo ra
    nhiều luồng để cùng chạy đoạn mã bên trong khối { ... }
*/
// int main() {
//     #pragma omp parallel
//     {
//         // Mỗi luồng đều thực hiện đoạn code này
//         printf("Hello from thread %d \n", omp_get_thread_num());
//     }
//     return 0;
// }

// 2
/*
    #prama omp for : chia vòng lặp cho các luồng hiện có
    // lưu ý: chỉ hoạt động bên trong 1 khối
*/
// int main() {
//     // tạo vùng song song
//     #pragma omp parallel
//     {
//         // chia vòng lặp for cho các luồng hiện có
//         #pragma omp for
//         for(int i = 0; i < 8; i++) {
//             printf("Thread %d dang xu li i = %d \n", omp_get_thread_num(), i);
//         }
//     }
//     return 0;
// }
