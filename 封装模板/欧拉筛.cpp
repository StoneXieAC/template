std::vector<int> prime;
std::vector<bool> np;

void Euler(int n) {
    prime.clear();
    np.assign(n + 1, false);
    np[0] = np[1] = true;

    for (int i = 2; i <= n; ++i) {
        if (!np[i]) prime.push_back(i);
        for (int j : prime) {
            if (i * j > n) break;
            np[i * j] = true;
            if (i % j == 0) break;
        }
    }
}
