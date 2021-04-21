ll qpow(ll x, ll n, ll m = MOD) {
//    assert(m > 1 and n >= 0);
//    if (x < 0 or x > m) x = (x % m + m) % m;
    ll res = 1;
    for (; n; n >>= 1, x = x * x % m)
        if (n & 1) res = res * x % m;
    return res;
}
|
