#include <iostream>

int main()
{
	int N, K, L;
	std::cin >> N >> K >> L;
	--K; --L;

	int size = (1 << N) - 1;
	for (int i = K; i <= L; ++i) {
		int n = N;
		int k = i;
		while (k > 0) {
			k = (k - 1) % ((1 << (n - 1)) - 1);
			--n;
		}
		std::cout << char('a' + n - 1);
	}
	std::cout << std::endl;
}