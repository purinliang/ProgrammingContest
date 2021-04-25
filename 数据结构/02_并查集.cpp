/** 并查集1 */
// 路径压缩
struct DisjointSetUnion {
    static const int MAXN = 5e5 + 5;
    int root[MAXN];
    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void init(int n) {
        for (int i = 1; i <= n; ++i) root[i] = i;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        root[x] = y;
        return 1;
    }
} dsu;


/** 并查集2 */
// 路径压缩+启发式合并
struct DisjointSetUnion {
    static const int MAXN = 5e5 + 5;
    int root[MAXN], siz[MAXN];
    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void init(int n) {
        for (int i = 1; i <= n; ++i) root[i] = i, siz[i] = 1;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (siz[x] > siz[y]) swap(x, y);
        root[x] = y, siz[y] += siz[x];
        return 1;
    }
} dsu;


/** 最小生成树克鲁斯克尔算法 */
struct Graph {
    static const int MAXN = 5e5 + 5;
    static const int MAXM = 5e5 + 5;
    int root[MAXN], m;
    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        root[x] = y;
        return 1;
    }
    struct Edge {
        int u, v;
        ll w;
        bool operator<(const Edge& e)const {
            return w < e.w;
        }
    } edge[MAXM];
    void init(int n) {
        for (int i = 1; i <= n; ++i) root[i] = i;
        m = 0;
    }
    void addEdge() {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        edge[++m] = {u, v, w};
    }
    void addEdge(int u, int v, ll w) {
        edge[++m] = {u, v, w};
    }
    ll mst() {
        sort(edge + 1, edge + 1 + m);
        ll res = 0;
        for (int i = 1; i <= m; ++i) {
            auto [u, v, w] = edge[i];
            if (merge(u, v)) res += w;
        }
        return res;
    }
} g;

