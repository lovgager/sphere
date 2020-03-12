#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int *A = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int i = 0, j = 0, buf = 0, sum = 0;
    const int modulo = 1000000000;
    bool read = true, odd = true;
    while (i < N && j < N) {
        int max, min;
        if (read) std::cin >> buf;

        if (A[i] > buf) {
            max = A[i];
            min = buf;
            read = true;
            ++j;
        }
        else {
            max = buf;
            min = A[i];
            ++i;
            read = false;
        }
        if (odd) sum = (sum + min % modulo) % modulo;
        odd = !odd;
    }

    while (i < N) {
        if (odd) sum = (sum + A[i] % modulo) % modulo;
        ++i;
        odd = !odd;
    }

    while (j < N) {
        if (odd) sum = (sum + buf % modulo) % modulo;
        ++j;
        if (j < N) std::cin >> buf;
        odd = !odd;
    }
    std::cout << sum << std::endl;
}
