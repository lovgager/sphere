#include <iostream>

int main() {
	const int KMAX = 20000000;
	int M, N;
	std::cin >> M >> N;
	bool* notPrime = new bool[KMAX + N]{};
	for (int i = 2; i * i < KMAX + N; ++i) {
		if (!notPrime[i]) {
			for (int j = i * i; j < KMAX + N; j += i) {
				notPrime[j] = 1;
			}
		}
	}

	int primeCount = 0, K = 2;
	for (int i = 2; i < 2 + N; ++i) {
		if (!notPrime[i]) ++primeCount;
	}
	while (primeCount != M && K <= KMAX) {
		primeCount -= !notPrime[K];
		primeCount += !notPrime[K + N];
		++K;
	}
	
	if (K > KMAX) std::cout << -1;
	else std::cout << K;
	std::cout << std::endl;
	return 0;
}