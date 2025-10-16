struct MF {
    struct edge {
        int v, nxt;
        ll cap, flow;
    } e[M];

    int fir[N], cnt = 0;

    int n, S, T;
    ll maxflow = 0;
    int dep[N], cur[N];

    void init(int siz, int s, int t) {
        memset(fir, -1, sizeof fir);
        cnt = 0;
        maxflow = 0;
        n = siz;
        S = s;
        T = t;
    }

    void addedge(int u, int v, ll w) {
        e[cnt] = {v, fir[u], w, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
    }

    bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));

        dep[S] = 1;
        q.push(S);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if ((!dep[v]) && (e[i].cap > e[i].flow)) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[T];
    }

    ll dfs(int u, ll flow) {
        if ((u == T) || (!flow)) return flow;

        ll ret = 0;
        for (int &i = cur[u]; ~i; i = e[i].nxt) {
            int v = e[i].v;
            ll d;
            if ((dep[v] == dep[u] + 1) &&
                (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == flow) return ret;
            }
        }
        return ret;
    }

    ll dinic() {
        while (bfs()) {
            memcpy(cur, fir, sizeof(int) * (n + 1));
            maxflow += dfs(S, INF);
        }
        return maxflow;
    }
} mf;
