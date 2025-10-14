std::vector<int> getNext(const std::string &s) {
    int n = s.size();
    std::vector<int> nex(n + 1, -1);
    int i = 0, j = -1;

    while (i < n) {
        if (j == -1 || s[i] == s[j]) {
            ++i, ++j;
            nex[i] = j;
        } else {
            j = nex[j];
        }
    }
    return nex;
}

int KMP(const std::string &a, const std::string &b) {
    if (b.empty()) return 0;
    std::vector<int> nex = getNext(b);
    int i = 0, j = 0, res = 0;

    while (i < (int) a.size()) {
        if (j == -1 || a[i] == b[j]) {
            ++i, ++j;
        } else {
            j = nex[j];
        }
        if (j == (int) b.size()) {
            ++res;
            j = nex[j];
        }
    }
    return res;
}
