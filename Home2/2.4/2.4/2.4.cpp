#include <iostream>
#include <map>

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::map<int, long long> rems{};
    std::string res = "";
    bool flag = true;
    long long index = 1;
    while (N % M && flag) {
        int rem = N % M;
        N *= 10;
        char c = char('0' + N / M);
        if (rems[rem]) {
            res.insert(rems[rem] - 1, "(");
            flag = false;
        }
        else {
            res += c;
            rems[rem] = index;
        }
        N %= M;
        ++index;
    }
    std::cout << "0." << res;
    if (!flag) std::cout << ")";
    std::cout << std::endl;
}