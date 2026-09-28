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
            ft[i] %= MOD;
        }
    }
    ll rsq(int i) {
        ll sum = 0;
        for (; i > 0; i -= LSOne(i)) {
            sum += ft[i];
            sum %= MOD;
        }
        return sum;
    }
};




int main() {
    speedup
    int n; cin >> n;
    vector<pii> a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f; a[i].s = i;
        b[i] = a[i].f;
    }
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i].f] = i;
    }
    int ans = 0;
    FenwickTree T(n);
    for (int i = 0; i < n; i++) {
        ans = (ans+T.rsq(mp[b[i]])+1)%MOD;
        T.upd(mp[b[i]]+1,(T.rsq(mp[b[i]])+1)%MOD);
    }
    cout << (ans%MOD+MOD)%MOD << '\n';
    return 0;
}
