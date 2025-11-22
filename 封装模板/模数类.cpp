template<int MOD>
struct ModNum {
    int x;

    ModNum() : x(0) {}

    template<class T>
    static int norm(T v) {
        v %= MOD;
        if (v < 0) v += MOD;
        return (int) v;
    }

    template<class T>
    ModNum(T v) {
        x = norm(v);
    }


    int val() const { return x; }

    template<class T>
    ModNum pow(T e) const {
        int base = x, res = 1;
        while (e) {
            if (e & 1) res = 1LL * res * base % MOD;
            base = 1LL * base * base % MOD;
            e >>= 1;
        }
        return ModNum(res);
    }


    ModNum operator+(const ModNum &other) const {
        int t = x + other.x;
        if (t >= MOD) t -= MOD;
        return ModNum(t);
    }

    ModNum operator-(const ModNum &other) const {
        int t = x - other.x;
        if (t < 0) t += MOD;
        return ModNum(t);
    }

    ModNum operator*(const ModNum &other) const {
        return ModNum(1LL * x * other.x % MOD);
    }

    ModNum inv() const {
        return pow(MOD - 2);
    }

    ModNum operator/(const ModNum &other) const {
        return *this * other.inv();
    }

    ModNum &operator+=(const ModNum &other) { return *this = *this + other; }

    ModNum &operator-=(const ModNum &other) { return *this = *this - other; }

    ModNum &operator*=(const ModNum &other) { return *this = *this * other; }

    ModNum &operator/=(const ModNum &other) { return *this = *this / other; }

    bool operator==(const ModNum &other) const { return x == other.x; }

    bool operator!=(const ModNum &other) const { return x != other.x; }

    ModNum &operator++() {
        x++;
        if (x == MOD) x = 0;
        return *this;
    }

    ModNum &operator--() {
        if (x == 0) x = MOD;
        x--;
        return *this;
    }

    ModNum operator++(signed) {
        ModNum t = *this;
        ++*this;
        return t;
    }

    ModNum operator--(signed) {
        ModNum t = *this;
        --*this;
        return t;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModNum &v) {
        return os << v.x;
    }

    friend std::istream &operator>>(std::istream &is, ModNum &v) {
        long long y;
        is >> y;
        v.x = norm(y);
        return is;
    }
};

const long long M = 998244353;
using mint = ModNum<M>;

std::array<std::vector<mint>, 2> getfac(int siz) {
    std::vector<mint> fac(siz + 1), inv(siz + 1);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= siz; i++) fac[i] = fac[i - 1] * i;
    inv[siz] = mint(1) / fac[siz];
    for (int i = siz - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1);
    return {fac, inv};
}

auto [fac, inv] = getfac(1000005);

mint C(int nn, int mm) {
    if (mm == 0 || nn == mm) return mint(1);
    if (nn <= 0 || nn < mm) return mint(0);
    return fac[nn] * inv[mm] * inv[nn - mm];
}

mint A(int nn, int mm) {
    if (nn <= 0 || nn < mm) return mint(0);
    return fac[nn] * inv[nn - mm];
}