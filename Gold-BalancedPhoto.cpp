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

const int MOD = 1e9+7;

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




int main() {
    usopen("bphoto")
    speedup
    int n; cin >> n;
    vi h(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        b[i] = h[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int> mp;
    int sz = b.size();
    for (int i = 0; i < sz; i++) {
        mp[b[i]] = i;
    }
    FenwickTree L(sz), R(sz);
    for (int i = 0; i < n; i++) {
        R.upd(mp[h[i]]+1, 1);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l = L.rsq(sz)-L.rsq(mp[h[i]]+1);
        ll r = R.rsq(sz)-R.rsq(mp[h[i]]+1);
        if (l > 2*r || r > 2*l) {
            ans++;
        }
        L.upd(mp[h[i]]+1, 1);
        R.upd(mp[h[i]]+1, -1);
    }
    cout << ans << '\n';
    return 0;
}
