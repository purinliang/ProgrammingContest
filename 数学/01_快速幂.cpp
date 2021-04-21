/** 二进制快速幂 */
ll qpow(ll x, ll n, ll m = MOD) {
//    assert(m > 1 and n >= 0);
//    if (x < 0 or x >= m) x = (x % m + m) % m;
    ll res = 1;
    for (; n; n >>= 1, x = x * x % m)
        if (n & 1) res = res * x % m;
    return res;
}

/** 二进制快速乘 */
ll qmul(ll a, ll b, ll m = MOD) {
//    assert(m > 1);
//    if (a < 0 or a >= m) a = (a % m + m) % m;
//    if (b < 0 or b >= m) b = (b % m + m) % m;
    ll res = 1;
    for (; b; b >>= 1, a = (a + a) % m)
        if (b & 1) res = (res + a) % m;
    return res;
}

/** 光速乘 */
ll qqmul(ll a, ll b, ll m = MOD) {
//    assert(m > 1);
//    if (a < 0 or a >= m) a = (a % m + m) % m;
//    if (b < 0 or b >= m) b = (b % m + m) % m;
    ull res = (ull) a * b - (unsigned)((long double)a / m * b + 0.5L) * m;
    return res < m ? res : res + m;
}

