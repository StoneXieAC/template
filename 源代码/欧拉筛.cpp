//
#include<bits/stdc++.h>

using namespace std;
namespace Euler1 {
    const int N = 1e7 + 10;
    int prime[N], tot = 0;
    bool notprime[N] = {1, 1};

    void Euler(int n) {
        for (int i = 2; i <= n; i++) {
            if (!notprime[i]) prime[++tot] = i;
            for (int j = 1; j <= tot; j++) {
                if (i * prime[j] > n) break;
                notprime[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
    }
}
namespace Euler2 {
    const int N = 1e7 + 10;
    std::vector<int> prime;
    bool notprime[N] = {1, 1};

    void Euler(int n) {
        for (int i = 2; i <= n; i++) {
            if (!notprime[i]) prime.push_back(i);
            for (int j: prime) {
                if (i * j > n) break;
                notprime[i * j] = true;
                if (i % j == 0) break;
            }
        }
    }
}
