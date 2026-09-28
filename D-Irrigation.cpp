#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>

#define LSOne(x) (x&(-x))
#define bs bitset<40>


class FenwickTree {
private:
    int m;
    vll ft;
public:
    FenwickTree(int sz) {ft.assign(sz+1, 0); m = sz;}

    void build(const vll &f) {
        m = f.size()-1;
        int sz = f.size()-1;
        ft.assign(sz+1, 0);
        for (int i = 1; i <= sz; i++) {
            ft[i] += f[i];
            if (i+LSOne(i) <= m)
                ft[i+LSOne(i)] += ft[i];
        }
    }
    FenwickTree(const vll &f) {build(f);}

    void upd(int i, ll c) {
        for (; i <= m; i += LSOne(i)) {
            ft[i] += c;
        }
    }
    ll rsq(int i) {
        ll sum = 0;
        for (; i > 0; i -= LSOne(i)) {
            sum += ft[i];
        }
        return sum;
    }
};

struct Event {
    char c;
    int x, y;
};
int main() {
    speedup
    int n, m, q; cin >> n >> m >> q;
    vector<pll> a(m);
    for (int i = 0; i < n; i++) {
        int c; cin >> c; c--;
        a[c].f++;
    }
    for (int i = 0; i < m; i++) {
        a[i].s = i;
    }
    sort(a.begin(), a.end());
    FenwickTree T(m-1);
    for (int i = 1; i < m; i++) {
        T.upd(i, (a[i].f-a[i-1].f)*i);
    }
    vector<pll> b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i].f;
        b[i].f -= n;
        b[i].s = i;
    }
    sort(b.begin(), b.end());
    int c = 0;
    int i = 0;
    vll ans(q);
    FenwickTree l(m);
    l.upd(a[0].s+1, 1);
    while (c < m-1 && i < q) {
        if (b[i].f <= T.rsq(c+1)) {
            ll cur = b[i].f-T.rsq(c);
            ll kth = (cur-1)%(c+1)+1;
            int lo = 1, hi = m, fa = -1;
            while (hi >= lo) {
                int md = (hi+lo)/2;
                if (l.rsq(md) >= kth) {
                    fa = md;
                    hi = md-1;
                }else {
                    lo = md+1;
                }
            }
            ans[b[i].s] = fa;
            i++;
        }else {
            c++;
            l.upd(a[c].s+1, 1);
        }
    }

    while (i < q) {
        ll d = b[i].f;
        d -= T.rsq(m-1);
        ans[b[i].s] = (d-1)%m+1;
        i++;
    }
    for (i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
