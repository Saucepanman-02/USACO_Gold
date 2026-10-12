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

const int MAXN = 2*1e7+10;

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

ll pw(ll a, ll b, ll mod) {
    ll pwr = 1;
    while (b) {
        if (b&1) pwr  = pwr*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return pwr;
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, c; cin >> a >> b >> c;
        ll ep = pw(b, c, MOD-1);
        cout << pw(a, ep, MOD) << '\n';
    }
    return 0;
}
