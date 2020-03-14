#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	double x;
	std::vector<double> v;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		v.push_back(x);
	}
	std::sort(v.begin(), v.end());

	if (v.begin() == v.end()) {
		std::cout << 0 << std::endl;
		return 0;
	}

	int res = 1;
	auto iter = v.begin();
	double lastPoint = *iter;
	while (iter < v.end()) {
		if (*iter <= lastPoint + 1) {
			++iter;
		} else {
			++res;
			lastPoint = *iter;
		}
	}

	std::cout << res << std::endl;
}