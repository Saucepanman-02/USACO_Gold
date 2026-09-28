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
#define l(p) (p << 1)
#define r(p) ((p<<1)+1)

#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

#define mk make_pair

#define bs bitset<45>

#define INF 1e9+5

class SegmentTree {
private:
    int n;
    vll A;
    vll st;
    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
            return;
        }
        int m = (L+R)/2;
        build(l(p), L, m);
        build(r(p), m+1, R);
        st[p] = st[l(p)]+st[r(p)];
    }
    void upd(int p, int L, int R, int idx, int val) {
        if (L == R) {
            st[p] += val;
            return;
        }
        int m = (L+R)/2;
        if (idx <= m) {
            upd(l(p), L, m, idx, val);
        }else {
            upd(r(p), m+1, R, idx, val);
        }
        st[p] = st[l(p)]+st[r(p)];
    }
    ll qur(int p, int L, int R, int i, int j) {
        if (i > j)
            return 0;
        if (i <= L && R <= j) {
            return st[p];
        }
        int m = (L+R)/2;
        return qur(l(p), L, m, i, min(j, m)) + qur(r(p), m+1, R, max(i, m+1), j);
    }
public:
    SegmentTree(vector<ll> & a) {A = a; n = a.size(); st.assign(4*n, 0); build(1, 0, n-1);}
    void upd(int idx, int val) {
        upd(1, 0, n-1, idx, val);
    }
    ll qur(int l, int r) {
        return qur(1, 0, n-1, l, r);
    }
};



int main() {
    speedup
    int n, m; cin >>  n >> m;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vll b(n+2);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i]-a[i-1];
    }
    SegmentTree T(b);
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        if (c == 1) {
            int r, s, u; cin >> r >> s >> u;
            T.upd(r, u);
            T.upd(s+1, -u);
        }else {
            int x; cin >> x;
            cout << T.qur(1, x) << '\n';
        }

    }
    return 0;
}
