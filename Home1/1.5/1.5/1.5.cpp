#include <iostream>

int main() {
	enum { S, NCOMM1, COMM1, ECOMM1, COMM2, NCOMM3, COMM3, ECOMM3, LIT } state = S;
	char c;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
	while ((c = getchar()) != EOF) {
		if (state == S && c == '(') state = NCOMM1;
		else if (state == NCOMM1 && c == '\'') state = LIT;
		else if (state == NCOMM1 && c != '*') state = S;
		else if (state == NCOMM1 && c == '*') state = COMM1;
		else if (state == COMM1 && c == '*') state = ECOMM1;
		else if (state == ECOMM1 && c != ')') state = COMM1;
		else if (state == ECOMM1 && c == ')') {
			state = S;
			++k1;
		}
		else if (state == S && c == '{') state = COMM2;
		else if (state == COMM2 && c == '}') {
			state = S;
			++k2;
		}
		else if (state == S && c == '/') state = NCOMM3;
		else if (state == NCOMM3 && c == '\'') state = LIT;
		else if (state == NCOMM3 && c != '/') state = S;
		else if (state == NCOMM3 && c == '/') state = COMM3;
		else if (state == COMM3 && c == '\n') {
			state = S;
			++k3;
		}
		else if (state == S && c == '\'') state = LIT;
		else if (state == LIT && c == '\'') {
			state = S;
			++k4;
		}
	}

	std::cout << k1 << " " << k2 << " " << k3 << " " << k4 << std::endl;
}