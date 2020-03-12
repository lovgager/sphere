#include <iostream>

int main()
{
    int N, M, MOD;
    std::cin >> N >> M >> MOD;
    long long* A = new long long[N + 1];
    long long* ptr = &A[N];
    long long in;
    for (int i = N; i >= 0; --i) {
        std::cin >> in;
        *ptr-- = in % MOD;
    }

    long long* X = new long long[N + 1];
    X[0] = 1;

    for (int j = 0; j < M; ++j) {
        long long res = 0, x;
        std::cin >> x;
        x %= MOD;
        X[1] = x;
        for (int i = 2; i <= N; ++i)
            if (i % 2) X[i] = X[i - 1] * x % MOD;
            else X[i] = X[i / 2] * X[i / 2] % MOD;

        ptr = A;
        for (int i = 0; i <= N; ++i) {
            res = (res + X[i] * *ptr++ % MOD) % MOD;
        }
        std::cout << res << std::endl;
    }
    return 0;
}