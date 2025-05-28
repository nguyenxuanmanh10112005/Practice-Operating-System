#include <stdio.h>
#include <omp.h>
typedef long long ll;

// Tính tổng S = 1 + 2 + 3 + 4 + ... + N dùng nhiều luồng với OpenMP
int main() {
    ll N = 100000;
    ll sum = 0;

    #pragma omp parallel for //reduction(+:sum)
    // khi không dùng reduction thì các luồng truy cập và ghi vào biến sum cùng lúc
    // => gây ra data race: nhiều luồng ghi đè dữ liệu lên nhau
    // => giá trị sum bị sai => kq sai

    // khi dùng reduction
    // mỗi luồng sẽ tạo ra bản sao riêng của sum (gọi là local sum)
    // khi vòng for kthuc thì sum cục bộ được cộng ại thành 1 sum tổng cuối cùng
    for (ll i = 0; i <= N; i++) {
        sum += i;
    }

    printf("Tong tu 1 den %lld la: %lld\n", N, sum);

    return 0;
}
