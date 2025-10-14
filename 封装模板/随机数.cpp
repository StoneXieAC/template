std::vector<long long> generate(int n, long long low = 0, long long high = LLONG_MAX, unsigned int seed = std::random_device{}()) {
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<long long> dis(low, high);

    std::vector<long long> res(n);
    for (auto &x : res) x = dis(gen);

    return res;
}