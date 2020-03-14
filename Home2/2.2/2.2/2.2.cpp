#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n, r;
	std::cin >> n >> r;
	std::vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i];
	}
	std::sort(x.begin(), x.end());

	int sum = 0;
	int minX = x[0];
	for (int j = 0; j < n; ++j) {
		sum += (x[0] - x[j] + r) % r;
	}
	int min = sum;
	for (int i = 1; i < n; ++i) {
		sum += (x[i] - x[i - 1]) * (n - 1);
		sum -= r - x[i] + x[i - 1];
		if (sum < min) {
			min = sum;
			minX = x[i];
		}
		else if (sum == min && x[i] < minX) {
			minX = x[i];
		}
	}

	std::cout << minX << std::endl;
	return 0;
}