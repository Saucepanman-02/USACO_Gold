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

#define MAXN (int)(2*1e5+5)

const int MOD = 1e9+7;
ll fac[MAXN];

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) {
            ans =ans*a%MOD;
        }
        a = a*a%MOD;
        b >>= 1;
    }
    return ans;
}


int main() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = i*fac[i-1]%MOD;
    }
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int r = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            while (r < n-1 && a[r+1]-a[i] <= k) {
                r++;
            }
            int c = r-i;
            if (c >= m-1) {
                ans += fac[c]*pw(fac[m-1], MOD-2)%MOD*pw(fac[c-(m-1)], MOD-2)%MOD;
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
