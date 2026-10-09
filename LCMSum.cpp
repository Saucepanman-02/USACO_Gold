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

const int MAXN = 1e6+10;

int max_div[MAXN];
void pfactor() {
    for (int i = 1; i < MAXN; i++) {
        max_div[i] = i;
    }
    for (ll j = 2; j < MAXN; j++) {
        if (max_div[j] == j) {
            for (ll i = j*j; i < MAXN; i += j) {
                max_div[i] = j;
            }
        }
    }
}
const int MOD = 1e9+7;

ll pw(ll a, ll b) {
    ll pwr = 1;
    while (b) {
        if (b&1) pwr  = pwr*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return pwr;
}

int phi[MAXN];

void t() {
    for (int i = 1; i < MAXN; i++) {
        phi[i] = i;
    }
    for (int j = 2; j < MAXN; j++) {
        if (phi[j] == j) {
            for (int i = j; i < MAXN; i += j) {
                phi[i] -= phi[i]/j;
            }
        }
    }
}

ll f[MAXN];

void solve() {
    f[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        ll p = max_div[i];
        ll sum = 1;
        ll pow = 1;
        ll c = i;
        while (c%p == 0) {
            pow *= p;
            sum += pow*phi[pow];
            c /= p;
        }
        f[i] = f[c]*sum;
    }
}

int main() {
    speedup
    pfactor();
    t();
    solve();
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        cout << (f[x]+1)*x/2 << '\n';
    }
    return 0;
}
