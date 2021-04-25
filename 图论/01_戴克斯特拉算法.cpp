/** 戴克斯特拉算法 */
// https://www.luogu.com.cn/problem/P4779
struct Graph {
    static const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
    static const int GRAPH_MAXN = 1e6 + 5;
    int n;
    vector<pil> G[GRAPH_MAXN];
    ll dis[GRAPH_MAXN];
    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) G[i].clear();
    }
    void addEdge() {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        G[u].emplace_back(v, w);
    }
    void addEdge(int u, int v, ll w) {
        G[u].emplace_back(v, w);
    }
    void dijkstra(int s) {
        static priority_queue<pli, vector<pli>, greater<pli>> pq;
        for (int i = 1; i <= n; ++i) dis[i] = LINF;
        pq.emplace(dis[s] = 0, s);
        while (!pq.empty()) {
            auto [disu, u] = pq.top();
            pq.pop();
            if (disu > dis[u]) continue;
            for (auto [v, w] : G[u]) {
                if (dis[v] <= dis[u] + w) continue;
                pq.emplace(dis[v] = dis[u] + w, v);
            }
        }
    }
} g;
