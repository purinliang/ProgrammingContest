/** 树状数组 */
// https://www.luogu.com.cn/problem/P3374
struct BinaryIndexTree {
    static const int MAXN = 5e5 + 5;
    int n;
    ll sum[MAXN];
    void Add(int x, int v) {
        for (int i = x; i <= n; i += i & (-i)) sum[i] += v;
    }
    ll Sum(int x) {
        ll res = 0;
        for (int i = x; i; i -= i & (-i)) res += sum[i];
        return res;
    }
    void Init(int n) {
        this->n = n;
        memset(sum, 0, sizeof(sum[0]) * (n + 1));
    }
} bit;

/** 计算逆序对 */
// https://www.luogu.com.cn/problem/P1908
struct BinaryIndexTree {
    static const int MAXN = 5e5 + 5;
    int m, b[MAXN], sum[MAXN];
    void Add(int x, int v) {
        for (int i = x; i <= m; i += i & (-i)) sum[i] += v;
    }
    int Sum(int x) {
        int res = 0;
        for (int i = x; i; i -= i & (-i)) res += sum[i];
        return res;
    }
    ll Calc(int n, int *a) {
        for (int i = 1; i <= n; ++i) b[i] = a[i];
        sort(b + 1, b + 1 + n);
        m = unique(b + 1, b + 1 + n) - (b + 1);
        memset(sum, 0, sizeof(sum[0]) * (m + 1));
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            res += i - 1 - Sum(pos), Add(pos, 1);
        }
        return res;
    }
} bit;

