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
#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

const int MOD = 998244353;

ll pw(ll a, ll b) {
    ll cr = 1;
    while (b) {
        if (b&1) cr = cr*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return cr;
}

int main() {
    int q; cin >> q;
    deque<pll> dq;
    ll ca = 1, cb = 0;
    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        if (c==0) {
            ll a, b; cin >> a >> b;
            dq.push_back({a, b});
            ca *= a;
            ca %= MOD;
            cb *= a; cb %= MOD;
            cb += b; cb %= MOD;
        }else if (c == 1) {
            ll ra = dq.front().f, rb = dq.front().s;
            ca = ca*pw(ra, MOD-2)%MOD;
            cb -= (ca*rb)%MOD; cb = (cb+MOD)%MOD;
            dq.pop_front();
        }else {
            ll x; cin >> x;
            cout << (ca*x%MOD+cb)%MOD << '\n';
        }
    }
    return 0;
}
