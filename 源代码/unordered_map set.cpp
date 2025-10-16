struct SplitMix64 {
    static uint64_t mix(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        x = x ^ (x >> 31);
        return x;
    }
};

struct CustomHash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                std::chrono::steady_clock::now().time_since_epoch().count();
        return (size_t) SplitMix64::mix(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const std::pair <T1, T2> &p) const {
        size_t h1 = std::hash < T1 > {}(p.first);
        size_t h2 = std::hash < T2 > {}(p.second);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

struct array_hash {
    template<class T, size_t N>
    size_t operator()(const std::array <T, N> &arr) const {
        size_t seed = 0;
        for (const auto &elem: arr) {
            seed ^= std::hash < T > {}(elem) +
                                    0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};