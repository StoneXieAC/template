namespace TARJAN {
    int dfn[N], low[N], col[N], tot, cnt;
    stack<int> S;

    void tarjan(int v) {
        low[v] = dfn[v] = ++tot;
        S.push(v);
        for (auto u: E[v]) {
            if (!dfn[u]) {
                tarjan(u);
                low[v] = min(low[v], low[u]);
            } else if (!col[u]) {
                low[v] = min(low[v], dfn[u]);
            }
        }
        if (low[v] == dfn[v]) {
            col[v] = ++cnt;
            while (S.top() != v) {
                col[S.top()] = cnt;
                S.pop();
            }
            S.pop();
        }
    }
}
