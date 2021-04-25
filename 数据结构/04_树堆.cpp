/** 树堆 完整版 */
struct Treap {
#define ls ch[id][0]
#define rs ch[id][1]
    static const int TREAP_MAXN = 2e5 + 5;
    static const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
    int root, ch[TREAP_MAXN][2], rnd[TREAP_MAXN];
    ll cnt[TREAP_MAXN], siz[TREAP_MAXN];
    ll val[TREAP_MAXN], sum[TREAP_MAXN];
    int top, del[TREAP_MAXN];

    int NewNode(ll v, ll c) {
        int id = del[0] ? (del[del[0]--]) : ++top;
        ls = 0, rs = 0, rnd[id] = rand();
        cnt[id] = c, siz[id] = c;
        val[id] = v, sum[id] = c * v;
        return id;
    }
    void PushUp(int id) {
        siz[id] = siz[ls] + siz[rs] + cnt[id];
        sum[id] = sum[ls] + sum[rs] + cnt[id] * val[id];
    }
    void Rotate(int &id, int d) {
        int tmp = ch[id][d ^ 1];
        ch[id][d ^ 1] = ch[tmp][d];
        ch[tmp][d] = id, id = tmp;
        PushUp(ch[id][d]), PushUp(id);
    }
    /* Insert c nodes with value v */
    void InsertHelp(int &id, ll v, ll c) {
        if (!id) {
            id = NewNode(v, c);
            return;
        }
        if (v == val[id]) cnt[id] += c;
        else {
            int d = val[id] > v ? 0 : 1;
            InsertHelp(ch[id][d], v, c);
            Rotate(id, d ^ (rnd[id] < rnd[ch[id][d]]));
        }
        PushUp(id);
    }
    /* Remove at most c nodes with value v */
    void RemoveHelp(int &id, ll v, ll c) {
        if (!id) return;
        if (v != val[id]) RemoveHelp(ch[id][val[id] < v], v, c);
        else {
            if (cnt[id] > c) cnt[id] -= c;
            else if (ls || rs) {
                int d = (!rs || rnd[ls] > rnd[rs]);
                Rotate(id, d), RemoveHelp(ch[id][d], v, c);
            } else {
                del[++del[0]] = id, id = 0;
                return;
            }
        }
        PushUp(id);
    }

    void Init() {
        top = 0, root = 0;
    }
    /* Insert c nodes with value v */
    void Insert(ll v, ll c = 1) {
        InsertHelp(root, v, c);
    }
    /* Remove at most c nodes with value v */
    void Remove(ll v, ll c = 1) {
        RemoveHelp(root, v, c);
    }
    /* "Rank of value v" means the first node with value >= v */
    /* Get the rank of value v */
    int GetRank(ll v) {
        int id = root;
        ll res = 1;
        while (id) {
            if (val[id] > v) id = ls;
            else if (val[id] == v) {
                res += siz[ls];
                break;
            } else {
                res += siz[ls] + cnt[id];
                id = rs;
            }
        }
        return res;
    }
    /* Get the value with rank r */
    ll GetValue(ll r) {
        int id = root;
        ll res = LINF;
        while (id) {
            if (siz[ls] >= r) id = ls;
            else if (siz[ls] + cnt[id] >= r) {
                res = val[id];
                break;
            } else {
                r -= siz[ls] + cnt[id];
                id = rs;
            }
        }
        return res;
    }
    /* Get the value of last node with value < v */
    ll GetPrev(ll v) {
        int id = root;
        ll res = -LINF;
        while (id) {
            if (val[id] < v) res = val[id], id = rs;
            else d = ls;
        }
        return res;
    }
    /* Get the value of first node with value > v */
    ll GetNext(int v) {
        int id = root;
        ll res = LINF;
        while (id) {
            if (val[id] > v) res = val[id], id = ls;
            else id = rs;
        }
        return res;
    }
    /* Get the sum of nodes with value <= v. */
    ll GetSumValue(ll v) {
        int id = root;
        ll res = 0;
        while (id) {
            if (val[id] > v) id = ls;
            else if (val[id] == v) {
                res += sum[ls] + cnt[id] * val[id];
                break;
            } else {
                res += sum[ls] + cnt[id] * val[id];
                id = rs;
            }
        }
        return res;
    }
    /* Get the sum of the first r nodes */
    ll GetSumRank(ll r) {
        int id = root;
        ll res = 0;
        while (id) {
            if (siz[ls] >= r) id = ls;
            else if (siz[ls] + cnt[id] >= r) {
                res += sum[ls] + (r - siz[ls]) * val[id];
                break;
            } else {
                res += sum[ls] + cnt[id] * val[id];
                r -= siz[ls] + cnt[id];
                id = rs;
            }
        }
        return res;
    }
#undef ls
#undef rs
} treap;
