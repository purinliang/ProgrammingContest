/** 线性求组合数 */
struct Combi {
    static const int MOD = 1e9 + 7;
    static const int COMBI_MAXN = 1e6 + 5;
    ll fac[COMBI_MAXN], invfac[COMBI_MAXN];
    ll qpow(ll x, ll n) {
        ll res = 1;
        for (; n; n >>= 1, x = x * x % MOD)
            if (n & 1) res = res * x % MOD;
        return res;
    }
    void init() {
        if (fac[0]) return;
        fac[0] = 1;
        for (int i = 1; i < COMBI_MAXN; ++i)
            fac[i] = fac[i - 1] * i % MOD;
        invfac[COMBI_MAXN - 1] = qpow(fac[COMBI_MAXN - 1], MOD - 2);
        for (int i = COMBI_MAXN - 2; i >= 0; --i)
            invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
    ll A(int n, int m) {
        if (n < 0 or m < 0 or n < m) return 0;
        if (!fac[0]) init();
        return fac[n] * invfac[n - m] % MOD;
    }
    ll C(int n, int m) {
        if (n < 0 or m < 0 or n < m) return 0;
        if (!fac[0]) init();
        return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
    }
} combi;
