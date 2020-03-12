#include <iostream>

long long pow(long long x, long long p, int m) {
    if (p == 0) return 1;
    if (p & 1) return (x % m) * pow(x % m, p - 1, m) % m;
    long long y = pow(x % m, p / 2, m) % m;
    return (y * y) % m;
}

int main()
{
    long long X, P;
    int M;
    std::cin >> X >> P >> M;
    X %= M;

    std::cout << pow(X, P, M) << std::endl;
}