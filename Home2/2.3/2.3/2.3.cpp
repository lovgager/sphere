#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, bool>> timeValues;
	for (int i = 0; i < n; ++i) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int start = 3600 * h + 60 * m + s;
		scanf("%d:%d:%d", &h, &m, &s);
		int finish = 3600 * h + 60 * m + s;

		std::pair<int, bool> time1 = { start, 0 };
		std::pair<int, bool> time2 = { finish, 1 };
		timeValues.push_back(time1);
		timeValues.push_back(time2);
	}

	std::sort(timeValues.begin(), timeValues.end());
	int countStart = 0, max = 0;
	for (int i = 0; i < (n << 1); ++i) {
		if (timeValues[i].second == 0) {
			++countStart;
			if (countStart > max) max = countStart;
		}
		else --countStart;
	}

	std::cout << max << std::endl;
	return 0;
}