const double EPS = 1e-8;

int sign(double val) {
    if (fabs(val) < EPS) return 0;
    return val > 0 ? 1 : -1;
}

int dcmp(double val1, double val2) {
    return sign(val1 - val2);
}

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

struct Point {
    double x, y;
    Point(double a = 0.0, double b = 0.0) : x(a), y(b) {}

    friend Point operator+(const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    }

    friend Point operator*(const Point &a, double b) {
        return Point(a.x * b, a.y * b);
    }
    friend Point operator*(double b, const Point &a) {
        return Point(a.x * b, a.y * b);
    }
    friend Point operator/(const Point &a, double b) {
        return Point(a.x / b, a.y / b);
    }

    friend double operator*(const Point &a, const Point &b) {
        return a.x * b.x + a.y * b.y;
    }

    friend double operator%(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }

    friend bool operator==(const Point &a, const Point &b) {
        return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
    }
    friend bool operator!=(const Point &a, const Point &b) {
        return !(a == b);
    }

    double dis() const {
        return std::sqrt(x * x + y * y);
    }
    double ddis() const {
        return x * x + y * y;
    }

    friend std::istream &operator>>(std::istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};


// 两点间距离
double dis(const Point &a, const Point &b) {
    return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// 两点间距离的平方
double ddis(const Point &a, const Point &b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
