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
    usopen("sleepy")
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int idx = n-2;
    while (idx >= 0 && a[idx+1] > a[idx]) {
        idx--;
    }
    if (idx == -1) {
        cout << 0 << '\n';
        return 0;
    }
    vi l;
    for (int i = idx; i >= 0; i--) {
        l.push_back(a[i]);
    }
    FenwickTree T(n);
    for (int i = idx+1; i < n; i++) {
        T.upd(a[i], 1);
    }
    cout << idx+1 << '\n';
    while (!l.empty()) {
        int cur = l.back();
        cout << l.size()-1+T.rsq(cur);
        T.upd(cur, 1);
        l.pop_back();
        if (!l.empty()) {
            cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
