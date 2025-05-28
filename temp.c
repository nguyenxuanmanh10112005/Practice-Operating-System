#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

    // private
    // firstprivate - riêng cho mỗi luồng, khởi tạo giá trị ban đầu
    // lastprivate - thêm giá trị cuối cùng khi kết thúc công việc
    // shared - chia sẻ chung giữa các luồng
    // default - mặc định các phạm vi cho vùng song song (share || none)
    // reduction - IMPORTANT - 
    // copyin



int main() {
    int i , s = 0;
    #pragma omp parallel 
    {
        #pragma omp for reduction (+:s)
        {
            for(int i = 0; i <= 10000; i++) {
                s += i;
            }
        }
    }
    printf("Sum of 1 to 10000 equals: %d", s);
    return 0;
}

int check() {
    #pragma int omp_in_parallel() 
    #pragma void omp_set_dynamic()
    #pragma int omp_get_dynamic(int dynamic_thread)
    #pragma void_set_nested(int nested) // lồng vào nhau

    setenv omp_get_num_threads 16
}