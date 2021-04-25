/** 树状数组 */
// https://www.luogu.com.cn/problem/P3374
struct BinaryIndexTree {
    static const int MAXN = 5e5 + 5;
    int n;
    ll nd[MAXN];
    void add(int x, int v) {
        for (int i = x; i <= n; i += i & (-i)) nd[i] += v;
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i; i -= i & (-i)) res += nd[i];
        return res;
    }
    void init(int n) {
        this->n = n;
        memset(nd, 0, sizeof(nd[0]) * (n + 1));
    }
} bit;


/** 计算逆序对 */
// https://www.luogu.com.cn/problem/P1908
struct ReversePairs {
    static const int MAXN = 5e5 + 5;
    int m, b[MAXN], nd[MAXN];
    void add(int x, int v) {
        for (int i = x; i <= m; i += i & (-i)) nd[i] += v;
    }
    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= i & (-i)) res += nd[i];
        return res;
    }
    ll calc(int n, int *a) {
        for (int i = 1; i <= n; ++i) b[i] = a[i];
        sort(b + 1, b + 1 + n);
        m = unique(b + 1, b + 1 + n) - (b + 1);
        memset(nd, 0, sizeof(nd[0]) * (m + 1));
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            res += i - 1 - sum(pos), add(pos, 1);
        }
        return res;
    }
} rp;

