int nex[N], ext[N];

void qnex(const string &b) {
    int p = 0, k = 1, l;
    nex[0] = b.size();
    while (p + 1 < b.size() && b[p] == b[p + 1]) p++;
    nex[1] = p;
    for (int i = 2; i < b.size(); i++) {
        p = k + nex[k] - 1;
        l = nex[i - k];
        if (i + l <= p) nex[i] = l;
        else {
            int j = max(0ll, p - i + 1);
            while (i + j < b.size() && b[i + j] == b[j]) j++;
            nex[i] = j;
            k = i;
        }
    }
}

void exkmp(const string &a, const string &b) {
    qnex(b);
    int p = 0, k = 0, l;
    while (p < a.size() && p < b.size() && a[p] == b[p]) p++;
    ext[0] = p;
    for (int i = 1; i < a.size(); i++) {
        p = k + ext[k] - 1;
        l = nex[i - k];
        if (i + l <= p) ext[i] = l;
        else {
            int j = max(0ll, p - i + 1);
            while (i + j < a.size() && j < b.size() && a[i + j] == b[j]) j++;
            ext[i] = j;
            k = i;
        }
    }
}
