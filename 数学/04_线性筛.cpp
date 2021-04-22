/** 线性筛质数1 */
// p[i]: 第i个质数
// pn[i]：i是否是合数
namespace Sieve {
    static const int SIEVE_MAXN = 1e6 + 5;
    static const int SIEVE_MAXP = SIEVE_MAXN / 10;
    int ptop, p[SIEVE_MAXP];
    bitset<SIEVE_MAXN> pn;
    void sieve() {
        ptop = 0, pn[1] = 1;
        for (int i = 2; i < SIEVE_MAXN; ++i) {
            if (!pn[i]) p[++ptop] = i, pn[i] = i;
            for (int j = 1, t; j <= ptop; ++j) {
                if ((t = i * p[j]) >= SIEVE_MAXN) break;
                pn[t] = p[j];
                if (i % p[j] == 0) break;       // gcd(i, p[j]) == p[j]
            }
        }
        fprintf(stderr, "[INFO] SIEVE_MAXP = %d, ptop = %d\n", SIEVE_MAXP, ptop);
        assert(SIEVE_MAXP > ptop);
    }
};
using namespace Sieve;


/** 线性筛质数2 */
// p[i]: 第i个质数
// pm[i]：i的最小质因子
// pk[i]：i的最小质因子的幂
namespace Sieve {
    static const int SIEVE_MAXN = 1e6 + 5;
    static const int SIEVE_MAXP = SIEVE_MAXN / 10;
    int ptop, p[SIEVE_MAXP], pm[SIEVE_MAXN], pk[SIEVE_MAXN];
    void sieve() {
        memset(pm, 0, sizeof(pm)), ptop = 0, pm[1] = 1, pk[1] = 1;
        for (int i = 2; i < SIEVE_MAXN; ++i) {
            if (!pm[i]) p[++ptop] = i, pm[i] = i, pk[i] = i;
            for (int j = 1, t; j <= ptop; ++j) {
                if ((t = i * p[j]) >= SIEVE_MAXN) break;
                pm[t] = p[j];
                if (i % p[j] == 0) {
                    pk[t] = pk[i] * p[j];       // gcd(i, p[j]) == p[j]
                    break;
                } else pk[t] = pk[p[j]];        // gcd(i, p[j]) == 1
            }
        }
        fprintf(stderr, "[INFO] SIEVE_MAXP = %d, ptop = %d\n", SIEVE_MAXP, ptop);
        assert(SIEVE_MAXP > ptop);
    }
};
using namespace Sieve;
