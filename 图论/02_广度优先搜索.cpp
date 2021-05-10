/** 广度优先搜索 */
struct Graph {
    static const int INF = 0x3f3f3f3f;
    static const int GRAPH_MAXN = 1e6 + 5;
    int n;
    vector<int> G[GRAPH_MAXN];
    int dis[GRAPH_MAXN];

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
    }
    void addDirectedEdge(int u, int v) {
        G[u].emplace_back(v);
    }
    void addUndirectedEdge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void bfs(int s) {
        static queue<int> q;
        for (int i = 1; i <= n; ++i) {
            dis[i] = INF;
        }
        dis[s] = 0;
        q.emplace(s);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (dis[v] <= dis[u] + 1) continue;
                // WARNING: enqueue only if dis[v] > dis[u] + 1
                dis[v] = dis[u] + 1;
                q.emplace(v);
            }
        }
    }
} g;

/** 最短路计数 */
// https://www.luogu.com.cn/problem/P1144
struct Graph {
    static const int INF = 0x3f3f3f3f;
    static const int MOD = 100003;
    static const int GRAPH_MAXN = 1e6 + 5;
    int n;
    vector<int> G[GRAPH_MAXN];
    int dis[GRAPH_MAXN];
    int ans[GRAPH_MAXN];

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
    }
    void addDirectedEdge(int u, int v) {
        G[u].emplace_back(v);
    }
    void addUndirectedEdge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void bfs(int s) {
        static queue<int> q;
        for (int i = 1; i <= n; ++i) {
            dis[i] = INF;
            ans[i] = 0;
        }
        dis[s] = 0;
        ans[s] = 1;
        q.emplace(s);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (dis[v] <= dis[u] + 1) {
                    if (dis[v] == dis[u] + 1) {
                        ans[v] = (ans[v] + ans[u]) % MOD;
                    }
                    continue;
                }
                // WARNING: enqueue only if dis[v] > dis[u] + 1
                dis[v] = dis[u] + 1;
                ans[v] = ans[u];
                q.emplace(v);
            }
        }
    }
} g;