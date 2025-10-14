template<const long long MOD>
struct ModNum {
    using integer = long long;
    integer x;

    ModNum() : x(0ll) {}

    explicit ModNum(integer y) {
        if (0 <= y && y < MOD) x = y;
        else {
            x = y % MOD;
            if (x < 0) x += MOD;
        }
    }

    integer Int() { return x; }

    ModNum Pow(integer y) {
        integer res = 1, tmp = x;
        while (y) {
            if (y & 1) res = res * tmp % MOD;
            y >>= 1;
            tmp = tmp * tmp % MOD;
        }
        return ModNum(res);
    }

    ModNum &operator=(integer y) {
        if (0 <= y && y < MOD) x = y;
        else {
            x = y % MOD;
            if (x < 0) x += MOD;
        }
        return *this;
    }

    bool operator==(integer y) const { return x == y; }

    bool operator==(ModNum y) const { return x == y.x; }

    bool operator!=(integer y) const { return x != y; }

    bool operator!=(ModNum y) const { return x != y.x; }

    bool operator<(integer y) const { return x < y; }

    bool operator<(ModNum y) const { return x < y.x; }

    bool operator>(integer y) const { return x > y; }

    bool operator>(ModNum y) const { return x > y.x; }

    bool operator<=(integer y) const { return x <= y; }

    bool operator<=(ModNum y) const { return x <= y.x; }

    bool operator>=(integer y) const { return x >= y; }

    bool operator>=(ModNum y) const { return x >= y.x; }

    ModNum operator+(ModNum y) const {
        ModNum res;
        if (x + y.x < MOD) res.x = x + y.x;
        else res.x = x + y.x - MOD;
        return res;
    }

    ModNum operator-(ModNum y) const {
        ModNum res;
        if (x - y.x >= 0) res.x = x - y.x;
        else res.x = x - y.x + MOD;
        return res;
    }

    ModNum operator*(ModNum y) const {
        ModNum res;
        res.x = x * y.x % MOD;
        if (res.x < 0) res.x += MOD;
        return res;
    }

    ModNum operator/(ModNum y) const {
        ModNum res;
        res.x = x * y.Pow(MOD - 2).x % MOD;
        if (res.x < 0) res.x += MOD;
        return res;
    }

    ModNum operator+(integer y) const { return *this + ModNum(y); }

    ModNum operator-(integer y) const { return *this - ModNum(y); }

    ModNum operator*(integer y) const { return *this * ModNum(y); }

    ModNum operator/(integer y) const { return *this / ModNum(y); }

    void operator+=(ModNum y) { *this = *this + y; }

    void operator*=(ModNum y) { *this = *this * y; }

    void operator-=(ModNum y) { *this = *this - y; }

    void operator/=(ModNum y) { *this = *this / y; }

    void operator+=(integer y) { *this = *this + ModNum(y); }

    void operator-=(integer y) { *this = *this - ModNum(y); }

    void operator*=(integer y) { *this = *this * ModNum(y); }

    void operator/=(integer y) { *this = *this / ModNum(y); }

    ModNum operator^(integer y) { return Pow(y); }

    template<class T>
    friend bool operator==(T y, ModNum t) { return y == t.x; }

    template<class T>
    friend ModNum operator+(T t, ModNum y) { return ModNum(t) + y; }

    template<class T>
    friend ModNum operator*(T t, ModNum y) { return ModNum(t) * y; }

    template<class T>
    friend ModNum operator-(T t, ModNum y) { return ModNum(t) - y; }

    template<class T>
    friend ModNum operator/(T t, ModNum y) { return ModNum(t) / y; }

    void operator++() {
        ++x;
        if (x == MOD) x = 0;
    }

    void operator--() {
        if (x == 0) x = MOD;
        --x;
    }

    ModNum operator++(signed) {
        ModNum tmp = *this;
        ++x;
        if (x == MOD) x = 0;
        return tmp;
    }

    ModNum operator--(signed) {
        ModNum tmp = *this;
        if (x == 0) x = MOD;
        --x;
        return tmp;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModNum &obj) {
        os << obj.x;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, ModNum &obj) {
        is >> obj.x;
        if (obj.x < 0 || obj.x >= MOD) {
            obj.x = obj.x % MOD;
            if (obj.x < 0) obj.x += MOD;
        }
        return is;
    }
};

const long long M = 998244353;
using mint = ModNum<M>;

std::array<std::vector<mint>, 2> getfac(int siz) {
    std::vector <mint> fac(siz + 1), inv(siz + 1);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= siz; i++) fac[i] = fac[i - 1] * i;
    inv[siz] = 1 / fac[siz];
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