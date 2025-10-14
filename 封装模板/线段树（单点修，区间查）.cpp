template<typename Node>
class SegmentTree {
public:
    int n;
    std::vector<Node> tree;

    SegmentTree(const std::vector<long long> &arr) : n((int) arr.size() - 1) {
        tree.resize(4 * arr.size());
        build(1, 1, n, arr);
    }


    void update(int pos, long long val) {
        update(1, 1, n, pos, val);
    }

    Node query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }

private:
    void build(int rt, int l, int r, const std::vector<long long> &arr) {
        if (l == r) {
            tree[rt] = Node(arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid, arr);
        build(rt << 1 | 1, mid + 1, r, arr);
        tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
    }

    void update(int rt, int l, int r, int pos, long long val) {
        if (l == r) {
//            TODO: 选择对应的修改方式
//            tree[rt] = Node(val); return;            // 赋值修改
//            tree[rt] = tree[rt] + Node(val); return; // 增量修改
            std::cerr << "ERROR: 未选择单点修改方式（赋值 or 增量）" << std::endl;
            exit(-1);
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) update(rt << 1, l, mid, pos, val);
        else update(rt << 1 | 1, mid + 1, r, pos, val);
        tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
    }

    Node query(int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[rt];
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(rt << 1, l, mid, ql, qr);
        else if (ql > mid) return query(rt << 1 | 1, mid + 1, r, ql, qr);
        else return query(rt << 1, l, mid, ql, qr) + query(rt << 1 | 1, mid + 1, r, ql, qr);
    }
};

struct Node {
    long long sum;

    Node() : sum(0ll) {}

    explicit Node(long long v) : sum(v) {}

    friend Node operator+(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        return res;
    }
};