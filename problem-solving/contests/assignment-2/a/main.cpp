/*
 * 1001
 * */
#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long count = 0;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            count += __builtin_popcount(i);
        printf("%lld\n", count);
    }
    return 0;
}
