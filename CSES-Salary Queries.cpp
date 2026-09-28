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
    vi ft;
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

    void upd(int i, int c) {
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
    int n, q; cin >> n >> q;
    vi a(n);
    vi l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l.push_back(a[i]);
    }
    vector<Event> b(q);

    for (int i = 0; i < q; i++) {
        cin >> b[i].c >> b[i].x >> b[i].y;
        if (b[i].c == '!') {
            l.push_back(b[i].y);
        }
    }
    sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
    map<int, int> mp;
    int sz = l.size();
    for (int i = 0; i < sz; i++) {
        mp[l[i]] = i;
    }
    FenwickTree T(sz);
    for (int i = 0; i < n; i++) {
        T.upd(mp[a[i]]+1, 1);
    }
    for (int i = 0; i < q; i++) {
        if (b[i].c == '!') {
            int k, x; k = b[i].x, x = b[i].y; k--;
            T.upd(mp[a[k]]+1, -1);
            a[k] = x;
            T.upd(mp[a[k]]+1, 1);
        }else {
            int r, s; r = b[i].x, s = b[i].y;
            int lo = 0, hi = sz-1, la = -1;
            while (hi >= lo) {
                int md = (hi+lo)/2;
                if (l[md] >= r) {
                    la = md;
                    hi = md-1;
                }else {
                    lo = md+1;
                }
            }
            if (la == -1) {
                cout << 0 << '\n';
                continue;
            }
            lo = 0, hi = sz-1; int ha = -1;
            while (hi >= lo) {
                int md = (hi+lo)/2;
                if (l[md] <= s) {
                    ha = md;
                    lo = md+1;
                }else {
                    hi = md-1;
                }
            }
            if (ha == -1) {
                cout << 0 << '\n';
                continue;
            }
            cout << T.rsq(ha+1)-T.rsq(la) << '\n';
        }
    }
    return 0;
}
