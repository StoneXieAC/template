#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dis(1e15, 1e16);

    for (int i = 0; i < 20; ++i) {
        cout << dis(gen) << " ";
    }

    return 0;
}

